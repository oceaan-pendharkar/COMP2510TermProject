//This is where we will include our tests to show how it works with the ciphers.h file :)
#include <stdio.h>
#include "ciphers.h"

int main() {
//    char * encodedString = encode64Bit("green apple");
//    printf("%s", encodedString);
//    return 0;

    // KAAAATTTTTTTTTTTTTTTTEEEEEEEEEEEEEEEEEEEEEEEEEE'S TEST INPUUUTTTTTSSSS
    // CEASAR DECODEE!!!!!!!!!!!!!!!!!!!
    //    int codeKey;
//    char initialMessage[200];
//
//    printf("Enter the encrypted message: ");
//    fgets(initialMessage, sizeof(initialMessage), stdin);
//
//    printf("Enter key (must be an integer) ");
//    scanf("%d", &codeKey);
//
//    decode(initialMessage, codeKey);
//    printf("Decoded message: %s\n", initialMessage);
//
//    return 0;
// CEASAR ENCODE!!!!!!!!!!!!!!!!!!!
//    char inputMessage[100];
//    int encodeKey;
//
//    printf("Enter a message to encode: ");
//    fgets(inputMessage, sizeof(inputMessage), stdin);
//
//    printf("Enter the key used to encode (must be an integer): ");
//    scanf("%d", &encodeKey);
//
//    encrypt(inputMessage, encodeKey);
//
//    printf("Encoded message: %s\n", inputMessage);
//
//    return 0;

// BOOK ENCODE!!!!!!!!!!!!!!!!!!!
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
//
//    char messageToEncrypt[] = "Hello this is a cipher code for C. These numbers should gradually increase";
//    int messageLength = strlen(messageToEncrypt);
//
//    int letterPositions[ALPHABET_SIZE] = {0};
//
//    for (int i = 0; i < messageLength; i++) {
//        char currentLetter = messageToEncrypt[i];
//
//        if (currentLetter == ' ') {
//            printf("/ ");
//        } else if (isalpha(currentLetter)) {
//            currentLetter = toupper(currentLetter);
//
//            int positionInBook = findPositionInBook(file, currentLetter, letterPositions);
//
//            printf("%d ", positionInBook);
//
//            letterPositions[currentLetter - 'A'] = positionInBook + 1;
//
//            resetFilePosition(file);
//        }
//    }
//
//    fclose(file);
//    return 0;


}
