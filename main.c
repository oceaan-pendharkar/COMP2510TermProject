//This is where we will include our tests to show how it works with the ciphers.h file :)
#include <stdio.h>
#include "ciphers.h"
#include <string.h>
#include <stdlib.h>

int main() {
    //Oceaan's tests
//    char wordToEncode[] = "My name is Bob!";
//    char * encryptedWord = simpleSubstitutionEncode(wordToEncode);
//    printf("Encrypted word: %s\n", encryptedWord);
//    printf("Original word: %s\n", wordToEncode);
//    char * decryptedWord = simpleSubstitutionDecode(encryptedWord);
//    printf("Decrypted word: %s\n\n", decryptedWord);
//
//    char * encryptedWord2 = complexSubstitutionEncode(wordToEncode);
//    printf("Encrypted word with random key: %s\n", encryptedWord2);
//    printf("%lu %lu\n", strlen(encryptedWord2), strlen(wordToEncode));
//
//    char wordToDecode[] = "i4 6vi9 63 }3}!";
//    char * key = "v}Iw9=7%6A\"li63ku]3ysZEV42";
//    complexSubstitutionDecode(wordToDecode, key);
//
//    char * encodedString = encode64Bit("green apple");
//    printf("encoded string: %s\n", encodedString);
//    char * decodedString = decode64Bit("Z3JlZW4gYXBwbGU=");
//    printf("decoded string: %s\n", decodedString);
//    free(encodedString);
//    free(decodedString);

//    char text[100];
//    int rails;
//    printf("Enter the text:");
//    fgets(text, sizeof(text), stdin);
//
//    text[strcspn(text, "\n")] = '\0';
//

    // Test Atbash
//    char input[100];
//    printf("Enter text for Atbash cipher: ");
//    fgets(input, sizeof(input), stdin);
//    atbashCipher(input);
//    printf("Atbash cipher: %s\n", input);

    // Test ROT13
//    char ROT[100];
//    printf("Enter text for ROT13 cipher: ");
//    fgets(ROT, sizeof(ROT), stdin);
//    rot13Cipher(ROT);
//    printf("ROT13: %s\n", ROT);

    // Test Binary
//    char binary[100];
//    printf("Enter text for binary encoding: ");
//    fgets(binary, sizeof(binary), stdin);
//    char *binaryEncode = textToBinary(binary);
//    printf("Binary Encoding: %s\n", binaryEncode);
//    free(binaryEncode);


      // Testing Keyword Cipher
//    const char* keyword = "KEYWORD";
//    const char* plaintext = "HELLO";
//
//    // Generate cipher alphabet
//    char* cipher_alphabet = generateCipherAlphabet(keyword);
//    printf("Cipher Alphabet: %s\n", cipher_alphabet);
//
//    // Encrypt
//    char* ciphertext = cipherAlphabetEncrypt(plaintext, cipher_alphabet);
//    printf("Plaintext: %s\n", plaintext);
//    printf("Ciphertext: %s\n", ciphertext);
//
//    // Decrypt
//    char* decrypted_text = cipherAlphabetDecrypt(ciphertext, cipher_alphabet);
//    printf("Decrypted Text: %s\n", decrypted_text);
//
//    // Free allocated memory
//    free(cipher_alphabet);
//    free(ciphertext);
//    free(decrypted_text);


//    printf("Enter the number of rails:");
//    scanf("%d", &rails);
//
//    getchar();
//
//    railRoadCipherEncryption(text, rails);
//
//    printf("Encrypted Rail Fence Cipher: %s\n", text);
//
//    railRoadCipherDecryption(text, rails);
//    printf("Decrypted Rail Fence Cipher: %s\n", text);
//
//    char plaintext[] = "Hello";
//    const char key[] = "P";
//
//
//    simpleXORCipher(plaintext, key);
//    printf("Encrypted message: %s\n", plaintext);
//
//
//    simpleXORCipher(plaintext, key);
//    printf("Decrypted message: %s\n", plaintext);

////Vigenere
//    char *message = (char *)malloc(100 * sizeof(char));
//    char *key = (char *)malloc(100 * sizeof(char));
//    char *encryptOrDecrypt = (char *)malloc(100 * sizeof(char));
//    if (message == NULL || key == NULL) {
//        fprintf(stderr, "Memory allocation failed\n");
//        exit(EXIT_FAILURE);
//    }
//
//    printf("Please enter message:\n");
//    scanf("%[^\n]", message);
//    printf("Please enter keyword:\n");
//    scanf("%s", key);
//    printf("Encrypt (y/n):\n");
//    scanf("%s", encryptOrDecrypt);
//
//    printf("Original Message: %s\n", message);
//
//    if (strcmp(encryptOrDecrypt, "y") == 0) {
//        vigenereEncrypt(message, key, true);
//    } else {
//        vigenereEncrypt(message, key, false);
//    }
//
//    printf("Encrypted Message: %s\n", message);
////Morse
//    const char *inputText = "Hello, World! 123";
//    char inputCode[] = ".... . .-.. .-.. --- ,   .-- --- .-. .-.. -.. !   .---- ..--- ...--";
//
//    printf("Original Text: %s\n", inputText);
//
//    printf("Morse Code: ");
//    textToMorse(inputText);
//
//    printf("Decoded Morse: ");
//    morseToText(inputCode);
////Fractionated Morse
//    const char *inputText = "Hello World";
//    char inputCode[] = "agtcdhotqodtcjt";
//
//    printf("Original Text: %s\n", inputText);
//
//    printf("Morse Code: ");
//    fractionatedMorse(inputText);
//
//    unfractionatedMorse(inputCode);

//// Scytale

//    char message[100];
//    int key;
//    printf("Enter the message to cipherAlphabetEncrypt: ");
//    fgets(message, sizeof(message), stdin);
//    message[strcspn(message, "\n")] = '\0';
//
//    printf("Enter the key: ");
//    scanf("%d", &key);
//
//    scytaleEncrypt(message, key);

//    char message[100];
//    int key;
//
//    printf("Enter the encrypted message: ");
//    fgets(message, sizeof(message), stdin);
//    message[strcspn(message, "\n")] = '\0';
//
//    printf("Enter the key: ");
//    scanf("%d", &key);
//
//    scytaleDecrypt(message, key);

// -----------------------------KATE TESTS-----------------------------
// PLAYFAIR CIPHER
//#define SIZE 30
//
//    char messageString[SIZE], encodeKey[SIZE];
//
//    strcpy(encodeKey, "bcit");
//    printf("Key text: %s\n", encodeKey);
//
//    strcpy(messageString, "Hello my name is Kate");
//    printf("Plain text: %s\n", messageString);
//
//    encodePlayfair(messageString, encodeKey);
//
//    printf("Encoded text with playfair: %s\n", messageString);
//
//    return 0;
//// ceasar decode

//    int codeKey;
//    char initialMessage[200];
//
//    printf("Enter the encrypted message: ");
//    fgets(initialMessage, sizeof(initialMessage), stdin);
//
//    printf("Enter key (must be an integer) ");
//    scanf("%d", &codeKey);
//
//    CeasarDecode(initialMessage, codeKey);
//    printf("Decoded message: %s\n", initialMessage);
//
//    return 0;

//// ceasar decode

//    char inputMessage[100];
//    int encodeKey;
//
//    printf("Enter a message to encode: ");
//    fgets(inputMessage, sizeof(inputMessage), stdin);
//
//    printf("Enter the key used to encode (must be an integer): ");
//    scanf("%d", &encodeKey);
//
//    ceasarEncrypt(inputMessage, encodeKey);
//
//    printf("Encoded message: %s\n", inputMessage);
//
//    return 0;
//}

//// BOOK CIPHER ENCODE

//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#define MAX_BOOK_TITLE 50
//#define ALPHABET_SIZE 26
//#define MAX_WORD_LENGTH 50
//
//    char chosenBook[MAX_BOOK_TITLE];
//    printf("Choose the book you would like to use as a key: ");
//    scanf("%s", chosenBook);
//    FILE *file;
//    file = fopen(chosenBook, "r");
//    if (file == NULL) {
//        printf("Error opening the file.\n");
//        return 1; }
//    char messageToEncrypt[] = "Hello this is a cipher code for C. These numbers should gradually increase";
//    int messageLength = strlen(messageToEncrypt);
//    int letterPositions[ALPHABET_SIZE] = {0};
//    for (int i = 0; i < messageLength; i++) {
//        char currentLetter = messageToEncrypt[i];
//        if (currentLetter == ' ') {
//            printf("/ ");
//        } else if (isalpha(currentLetter)) {
//            currentLetter = toupper(currentLetter);
//
//            int positionInBook = BookCipherEncode(file, currentLetter, letterPositions);
//            printf("%d ", positionInBook);
//            letterPositions[currentLetter - 'A'] = positionInBook + 1;
//            resetFilePositionEncode(file);
//        }
//    }
//    fclose(file);
//    return 0;

/// BOOK CIPHER DECODE
//#define MAX_BOOK_TITLE 50
//
//    char chosenBook[MAX_BOOK_TITLE];
//    printf("Choose the book you would like to use as a key: ");
//    scanf("%s", chosenBook);
//
//    FILE *file;
//    file = fopen(chosenBook, "r");
//
//    if (file == NULL) {
//        printf("Error opening the file.\n");
//        return 1;
//    }
//
//    char messageToDecode[] = "43 91 9 20 51 / 2 55 10 1 / 15 5 / 13 / 4 21 42 57 101 32 / 26 56 44 168 / 18 62 138 / 30 / 25 60 338 7 353 / 29 6 3 11 423 145 14 / 16 66 67 8 142 124 / 269 149 35 136 17 38 199 204 58 / 106 59 45 159 427 40 22 449";
//
//    char *token = strtok(messageToDecode, " ");
//    while (token != NULL) {
//        if (strcmp(token, "/") == 0) {
//            printf(" ");
//        } else {
//            int positionInBook;
//            sscanf(token, "%d", &positionInBook);
//
//            char decodedLetter;
//            if (bookCipherDecode(file, positionInBook, &decodedLetter)) {
//                printf("%c", decodedLetter);
//            }
//            resetFilePosition(file);
//        }
//
//        token = strtok(NULL, " ");
//    }
//
//    fclose(file);
//    return 0;

}
