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
//    const char* plaintext = "HELLO WORLD";
//
//    char* encrypted_text = encrypt(plaintext, keyword);
//    char* decrypted_text = decrypt(encrypted_text, keyword);
//
//    printf("Plaintext: %s\n", plaintext);
//    printf("Encrypted text: %s\n", encrypted_text);
//    printf("Decrypted text: %s\n", decrypted_text);
//
//    free(encrypted_text);
//    free(decrypted_text);
//RailFence
//    int rails = 3;
//    char railFenceEncodeTest[10]= "HELLO";
//    char railFenceDecodeTest[10]= "HOELL";
//
//   railFenceCipherEncryption(railFenceEncodeTest, rails);
//
//    printf("Encrypted Rail Fence Cipher: %s\n", railFenceEncodeTest);
//
//    railFenceCipherDecryption(railFenceDecodeTest, rails);
//    printf("Decrypted Rail Fence Cipher: %s\n", railFenceDecodeTest);
//
//Scytale
//   char scytaleMessage[] = "Hello World";
//   char scytaleMessages[]= "HlWleoodl r" ;
//   int key= 3;
//
//    scytaleEncrypt(scytaleMessage, key);
//
//    scytaleDecrypt(scytaleMessages, key);
//SimpleXOR
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
//    printf("\nDeciphered Text: ");
//    unfractionatedMorse(inputCode);

//    char message[100];
//    int key;
//
//

}
