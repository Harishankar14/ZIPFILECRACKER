#include <iostream>
#include <cstdlib>
#include <array>
#include <memory>
#include <stdexcept>
#include <string>

void executeShellCommand(const std::string &command) {
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Error executing command: " << command << std::endl;
    }
}

std::string getCommandOutput(const std::string &command) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, int (*)(FILE*)> pipe(popen(command.c_str(), "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main() {
    try {
        // Set the locale for character type functions to C
        if (setlocale(LC_CTYPE, "C") == NULL) {
            std::cerr << "Error setting locale to C" << std::endl;
            return 1;
        }

        // Generate a random string of alphabetic characters and save it to cc.txt
        executeShellCommand("cat /dev/urandom | tr -dc '[:alpha:]' | fold -w 1000 | head -n 1 > cc.txt");

        // Create an encrypted zip archive containing cc.txt
        executeShellCommand("zip -e cctest.zip cc.txt");

        // Display the first 64 bytes of the cctest.zip file in hexadecimal format
        std::string xxdOutput = getCommandOutput("xxd -l64 cctest.zip");
        std::cout << "Hex dump of the first 64 bytes of cctest.zip:\n" << xxdOutput << std::endl;

        // Attempt to crack the password of cctest.zip using fcrackzip
        std::string fcrackzipOutput = getCommandOutput("fcrackzip -v -u -D -p ~/wordlists/rockyou.txt cctest.zip");
        std::cout << "fcrackzip output:\n" << fcrackzipOutput << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    return 0;
}
