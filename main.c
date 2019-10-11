#include <stdio.h>
#include <ctype.h>
#include "operations.h"

int main() {
    char option = 0;
    while(1) {
        // Print menu to the console
        printf("Select an option below\n"
               "1. Encryption\n"
               "2. Decryption\n"
               "q. Quit\n");
        scanf(" %c", &option); // Scan entered option character

        if (option == '1') { // Encryption
            printf("Plain text:");
            char* plain_text = get_text(256); // Get plain text to encrypt

            printf("Keyword:");
            char* keyword = get_text(256); // Get keyword
            char* encrypted = encrypt(plain_text, keyword); // Encrypt the plain text
            printf("Encrypted text: %s\n\n", encrypted); // Print encrypted text to the console
        }
        else if (option == '2') { // Decryption
            printf("Cipher text:");
            char* cipher_text = get_text(256); // Get cipher text to decrypt

            printf("Keyword:");
            char* keyword = get_text(256); // Get keyword
            char* decrypted = decrypt(cipher_text, keyword); // Decrypt the cipher text
            printf("Decrypted text: %s\n\n", decrypted); // Print decrypted text to the console
        }
        else if (tolower(option) == 'q') { // Quit
            printf("Program terminated\n\n"); // Print quit message and terminate the program
            break;
        }
    }

    return 0;
}