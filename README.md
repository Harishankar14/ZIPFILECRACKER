This project demonstrates the process of creating a password-protected ZIP file and then attempting to crack its password using a dictionary attack. It utilizes C++ to execute shell commands for file generation, encryption, and password cracking. The project showcases the integration of system commands within a C++ program to perform practical tasks related to cybersecurity and file handling.
Features

    Random String Generation:
        Generates a random string of alphabetic characters and saves it to a text file (cc.txt).

    Password-Protected ZIP File Creation:
        Creates an encrypted ZIP archive (cctest.zip) containing the text file, using a password provided by the user.

    Hex Dump Display:
        Displays the first 64 bytes of the created ZIP file in hexadecimal format for verification and analysis.

    Password Cracking Using Dictionary Attack:
        Attempts to crack the password of the encrypted ZIP file using fcrackzip and the popular rockyou.txt wordlist.

Implementation Details

    Language: C++
    Libraries/Tools Used:
        Standard C++ libraries: <iostream>, <cstdlib>, <array>, <memory>, <stdexcept>, <string>
        System commands: cat, tr, fold, head, zip, xxd, fcrackzip

Steps Involved

    Set Locale:
        Ensures the locale is set for character type functions.

    Random String Generation:
        Uses /dev/urandom to generate random alphabetic characters.
        Pipes the output through tr to filter alphabetic characters, fold to limit the line width, and head to get the first 1000 characters.
        Saves the output to cc.txt.

    ZIP File Creation:
        Executes the zip command to create an encrypted ZIP file (cctest.zip) containing cc.txt.
        The user is prompted to enter and verify the password for the ZIP file.

    Hex Dump:
        Uses xxd to display the first 64 bytes of the ZIP file in hexadecimal format, providing a snapshot of the file’s structure.

    Password Cracking:
        Executes fcrackzip with the rockyou.txt wordlist to attempt to crack the ZIP file's password.
        Outputs the result of the cracking attempt.

Usage

    Compilation:
        Compile the C++ program using a suitable compiler, e.g., g++ -o myprogram file.cpp.

    Execution:
        Run the compiled program: ./myprogram.
        Follow the prompts to set the password for the ZIP file.
        Observe the output, including the hex dump and the result of the password cracking attempt.

Prerequisites

    Dependencies:
        zip: To create the password-protected ZIP file.
        xxd: To display the hex dump.
        fcrackzip: To attempt the dictionary attack for password cracking.
        wget: To download the rockyou.txt wordlist if not already available.
    Wordlist:
        Ensure the rockyou.txt wordlist is downloaded and accessible at the specified path (~/wordlists/rockyou.txt).

This project provides a comprehensive example of automating the creation and security testing of password-protected ZIP files using C++ and various shell commands. It serves as an educational tool for understanding the intersection of programming, file handling, and cybersecurity.
