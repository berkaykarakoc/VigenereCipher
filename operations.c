#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "operations.h"

// Implementation of the method to get text from user
char* get_text(size_t size) {
    // Allocate a static memory for a text (can be converted to dynamic)
    char* text;
    text = malloc(sizeof(char)*size);

    // Get text from user
    scanf("%s", text);

    // Make entered plain text uppercase
    unsigned int i = 0;
    while(text[i] != '\0') {
        text[i] = (char) toupper(text[i]);
        i++;
    }

    // Return text
    return text;
}

// Implementation of the method to encrypt the plain text
char* encrypt(char* plain_text, const char* keyword) {

    // Allocate memory for encrypted text
    char* encrypted_text = malloc(sizeof(char)*(strlen(plain_text)+1));

    unsigned int i;
    for(i = 0; i < strlen(plain_text); i++) {
        // Calculate encrypted character for each character in plain text
        int encrypted_val = ((int) plain_text[i] + (int) *(keyword+(i % strlen(keyword)))) % 26 + 65;
        encrypted_text[i] = (char) encrypted_val;
    }

    // Terminate encrypted text
    encrypted_text[i] = '\0';

    // Return encrypted text
    return encrypted_text;
}

// Implementation of the method to decrypt the cipher text
char* decrypt(char* cipher_text, const char* keyword) {

    // Allocate memory for encrypted text
    char* decrypted_text = malloc(sizeof(char)*(strlen(cipher_text)));

    unsigned int i = 0;
    for(i = 0; i < strlen(cipher_text); i++) {
        // Calculate decrypted character for each character in cipher text
        int decrypted_val = (((int) cipher_text[i] - (int) *(keyword+(i % strlen(keyword)))) + 26) % 26 + 65;
        decrypted_text[i] = (char) decrypted_val;
    }

    // Terminate decrypted text
    decrypted_text[i] = '\0';

    // Return decrypted text
    return decrypted_text;
}