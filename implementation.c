//this is where we will put the implementations of all our functions.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


 // OOOOOCCCEEEEEEEAAAAAAANNNNNNNN??????????????????????????????????????????
//constants
const char * ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char * BASE64KEY = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

//helper functions
//1.
bool checkIfLetter(char c) {
    return c >= 65 && c <= 90 || c >= 97 && c <= 122;
}

//2.
int findIndex(char c, const char * string) {
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == c) {
            return i;
        }
    }
    return -1;
}

//5.
//gets an array of the number of times each character appears in a key
int * getCombinationsArray(char * string, char * key) {
    char * ptr;
    static int counts[] = {1};
    //initialize counts with zeros
    for (int i = 0; i < strlen(string); i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < strlen(string); i++) {
        int count = 0;
        ptr = &key[0];
        while (*ptr != '\0') {
            if (*ptr == string[i]) {
                count++;
            }
            ptr++;
        }
        counts[i] = count;
    }
    return counts;
}

//6.
//finds the indices of a certain char in a string
int * getIndices(char c, char * string) {
    int* indices = (int*) malloc(10 * sizeof(int));
    int index = 0;
    indices[0] = -1;
    for (int i = 0; i < strlen(string); i++) {
        if (string[i] == c) {
            indices[index] = i;
            index++;
        }
    }
    indices[index] = -1;
    return indices;
}

//7.
//Returns the ASCII code in decimal for a specified character
int getASCIICode(char c) {
    return (int) c;
}

//8.
//Converts a decimal number to a binary string of length 8
char * convertToBinaryString(int number) {
    int numberToSubtract = number;
    char * binary = (char*) malloc(9);
    binary[0] = '0';
    int index = 1;
    for (int i = 64; i > 0; i /= 2) {
        if (numberToSubtract >= i) {
            binary[index] = '1';
            numberToSubtract -= i;
        }
        else {
            binary[index] = '0';
        }
        index++;
    }
    return binary;
}

//9.
//Returns a string of binary digits to represent the ascii codes for chars in string
char * getBinaryString (char * stringToEncode) {
    char * binary = (char*) malloc((strlen(stringToEncode) * 9) + 1);
    int index = 0;
    for (int i = 0; i < strlen(stringToEncode); i++) {
        char * codeInBinaryForChar = convertToBinaryString(getASCIICode(stringToEncode[i]));
        for (int j = 0; j < strlen(codeInBinaryForChar); j++) {
            binary[index] = codeInBinaryForChar[j];
            index++;
        }
        free(codeInBinaryForChar);
    }
    if (strlen(binary) % 3 != 0) {
        int length = (int) strlen(binary);
        int numberOfZeroesToAdd = 24 - (length % 24);
        for (int i = 0; i < numberOfZeroesToAdd; i++) {
            binary[index] = '0';
            index++;
        }
    }
    return binary;
}

//10.
//Gives the number of equals signs needed at the end of a base64 encoded string.
int equalsSignsNeededAtEnd (char * stringToDecode) {
    int equalsSignsNeededAtEndOfEncodedString = 0;
    if (strlen(stringToDecode) % 3 == 2) {
        equalsSignsNeededAtEndOfEncodedString = 1;
    }
    else if (strlen(stringToDecode) % 3 == 1) {
        equalsSignsNeededAtEndOfEncodedString = 2;
    }
    return equalsSignsNeededAtEndOfEncodedString;
}

//11.
//Converts a 6-digit binary string to a base 64 char
char base64Char(const char * binaryString) {
    int index = 0;
    int number = 0;
    for (int i = 5; i >= 0; i--) {
        if (binaryString[index] == '1') {
            number += (int)pow(2, i);
        }
        index++;
    }
    return BASE64KEY[number];
}

//12.
//Adds the appropriate number of equals signs at the end of a string.
char * addEqualsSigns(char * encodedString, int numberOfEqualsSigns) {
    char * newString = (char*) malloc(strlen(encodedString) * sizeof(char) + numberOfEqualsSigns);
    for (int i = 0; i < strlen(encodedString); i++) {
        newString[i] = encodedString[i];
    }
    for (int i = 0; i < numberOfEqualsSigns; i++) {
        newString[strlen(encodedString) + i] = '=';
    }
    return newString;
}

//13.
//Converts a base 64 encoded char to a 6-digit binary string
char * binaryFromBase64Char(const char base64char) {
    char * binaryString = (char*) malloc(7);
    int indexToConvertToBinary = findIndex(base64char, BASE64KEY);
    int index = 0;
    for (int i = 5; i >= 0; i--) {
        if (indexToConvertToBinary >= pow(2, i)) {
            binaryString[index] = '1';
            indexToConvertToBinary -= (int)pow(2, i);
        }
        else {
            binaryString[index] = '0';
        }
        index++;
    }
    return binaryString;
}

//14.
//converts an eight-digit binary string into its corresponding ASCII letter
char getASCIILetterFromEightDigitBinary (const char * binaryString) {
    int number = 0;
    int binaryIndex = 0;
    for (int i = 7; i >=0; i--) {
        if (binaryString[binaryIndex] == '1') {
            number += (int)pow(2, i);
        }
        binaryIndex++;
    }
    return (char) number;
}

//15.
//Converts a string of chars into 6-digit binary for 64 bit decoding
char * getSixDigitBinaryForDecode(char * stringToDecode) {
    char * binary = (char*) malloc(strlen(stringToDecode) * 6 + 1);
    int binaryIndex = 0;
    for (int i = 0; i < strlen(stringToDecode); i++) {
        if (stringToDecode[i] != '=') {
            char * sixDigitBinaryString = binaryFromBase64Char(stringToDecode[i]);
            //add each 6-digit binary string to the longer binary string
            for (int j = 0; j < strlen(sixDigitBinaryString); j++) {
                binary[binaryIndex] = sixDigitBinaryString[j];
                binaryIndex++;
            }
        }
    }
    return binary;
}

//16.
//Converts 8 digits at a time from 6-digit binary decoded string
//returns decoded string in regular chars
char * decodeBinaryInGroupsOfEight(char * binary, int length) {
    char * decoded = (char*) malloc(length);
    unsigned long numberOfCharsLeftInBinaryString = strlen(binary);
    int binaryIndex = 0;
    int decodedIndex = 0;
    while(binaryIndex < strlen(binary) && numberOfCharsLeftInBinaryString >= 8) {
        char * eightDigitBinaryString = (char*) malloc(9);
        for (int i = 0; i < 8; i++) {
            eightDigitBinaryString[i] = binary[binaryIndex];
            binaryIndex++;
        }
        char decodedChar = getASCIILetterFromEightDigitBinary(eightDigitBinaryString);
        decoded[decodedIndex] = decodedChar;
        decodedIndex++;
        free(eightDigitBinaryString);
        numberOfCharsLeftInBinaryString -= 8;
    }
    return decoded;
}

//17.
//Converts 6 digits at a time from 8-digit binary encoded string
//returns encoded string in base 64 chars
char * encodeBinaryInGroupsOfSix(char * binaryString, int length, int charsToEncode) {
    char * encoded = (char*) malloc(length * 8);
    int encodedIndex = 0;
    int charsEncoded = 0;
    while (*binaryString != '\0' && charsToEncode != charsEncoded) {
        //get next 6 chars
        char nextSixDigits[] = "000000";
        for (int i = 0; i < 6; i++) {
            nextSixDigits[i] = *binaryString;
            binaryString++;
        }
        //convert those 6 digits to a base 64 character
        char base64char = base64Char(nextSixDigits);
        //put converted char into encoded string
        encoded[encodedIndex] = base64char;
        charsEncoded++;
        encodedIndex++;
    }
    return encoded;
}

//Prints the legend for complex substitution decode function
void printLegend() {
    printf("Legend:\nIf you see a slash '/' that means that character could be any of the characters."
           " Treat the slash like the word 'or'.\nIf you see a character with only space around it, that is the only"
           " character possible for that index of the decoded message based on the key provided.\n\n");
}

//gets a string of possible letters for a certain char within the alphabet
char * getStringOfPossibleLetters(const int * indices) {
    char * stringOfPossibleLetters = (char *) malloc(3);
    int iterationIndex = 0;
    while(indices[iterationIndex] >= 0) {
        int indexOfCharInKey = indices[iterationIndex];
        stringOfPossibleLetters[iterationIndex] = ALPHABET[indexOfCharInKey];
        iterationIndex++;
    }
    stringOfPossibleLetters[iterationIndex] = '\0';
    return stringOfPossibleLetters;
}

//prints the possible letters that a character could be in the alphabet
void printPossibleLetters(const int * indices) {
    int index = 0;
    while(indices[index] != -1) {
        printf("%c", ALPHABET[indices[index]]);
        index++;
        if (indices[index] != -1) {
            printf("/");
        }
        else {
            printf(" ");
        }
    }
}

//prints the possible chars for cases where possible chars = 1, more, or white space
void printCharactersAtIndex(int * indices) {
    if (indices[0] != -1 && indices[1] == -1) {
        printf("%c ", ALPHABET[indices[0]]);
    }
    else if (indices[0] != -1) {
        printPossibleLetters(indices);
    }
    else {
        printf(" *whitespace* ");
    }
}

char * simpleSubstitutionEncode (char * stringToEncode) {
    char * key = "MGFLHCWDZJPXTBEUAYNQSIKVRO";
    static char encodedString[] = {0};
    for (int i = 0; i < strlen(stringToEncode); i++) {
        if (checkIfLetter(stringToEncode[i])) {
            int index = findIndex((char) (toupper(stringToEncode[i])), ALPHABET);
            encodedString[i] = key[index];
        }
        else {
            encodedString[i] = stringToEncode[i];
        }
    }
    encodedString[strlen(stringToEncode)] = '\0';
    return encodedString;
}

char * simpleSubstitutionDecode(char * stringToDecode) {
    const char * key = "MGFLHCWDZJPXTBEUAYNQSIKVRO";
    char * decoded = (char*) malloc(strlen(stringToDecode));
    for (int i = 0; i < strlen(stringToDecode); i++) {
        if (checkIfLetter(stringToDecode[i])) {
            int index = findIndex((char) toupper(stringToDecode[i]), key);
            decoded[i] = ALPHABET[index];
        }
        else {
            decoded[i] = stringToDecode[i];
        }
    }
    decoded[strlen(stringToDecode)] = '\0';
    return decoded;
}

char * complexSubstitutionEncode (char * stringToEncode) {
    char key[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //placeholder
    char * encoded = (char*) malloc(strlen(stringToEncode) + 1);
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < strlen(ALPHABET); i++) {
        int charToAdd =  rand() % 93 + 33;
        key[i] = (char) charToAdd;
    }
    printf("Key used: %s\n", key);
    for (int i = 0; i < strlen(stringToEncode); i++) {
        if (checkIfLetter(stringToEncode[i])) {
            int index = findIndex((char)toupper(stringToEncode[i]), ALPHABET);
            encoded[i] = key[index];
        }
        else {
            encoded[i] = stringToEncode[i];
        }
    }
    return encoded;
}

void complexSubstitutionDecode (char * stringToDecode, char * key) {
    printLegend();
    for (int i = 0; i < strlen(stringToDecode); i++) {
        int * indices = getIndices(stringToDecode[i], key);
        char * stringOfPossibleLetters = getStringOfPossibleLetters(indices);
        printCharactersAtIndex(indices);
        free(indices);
        free(stringOfPossibleLetters);
    }
    int * combinations = getCombinationsArray(stringToDecode, key);
    int numberOfCombinations = 1;
    for (int i = 0; i < strlen(stringToDecode); i++) {
        if (combinations[i] != 0) {
            numberOfCombinations *= combinations[i];
        }
    }
    printf("\n\nBased on these possibilities you have %d possible combinations for your %lu-character string.\n",
           numberOfCombinations, strlen(stringToDecode));
}

char * encode64Bit (char * stringToEncode) {
    char * binaryString = getBinaryString(stringToEncode);
    int equalsSignsNeeded = equalsSignsNeededAtEnd(stringToEncode);
    int charsToEncode = ((int)strlen(binaryString) - (6 * equalsSignsNeeded))/6;
    char * encoded = encodeBinaryInGroupsOfSix(binaryString, (int) strlen(stringToEncode), charsToEncode);
    if (equalsSignsNeeded > 0) {
        encoded = addEqualsSigns(encoded, equalsSignsNeeded);
    }
    return encoded;
}

char * decode64Bit (char * stringToDecode) {
    char * binary = getSixDigitBinaryForDecode(stringToDecode);
    char * decoded = decodeBinaryInGroupsOfEight(binary, (int) strlen(stringToDecode));
    free(binary);
    return decoded;
}

// KKKKKKKKKKKKAAAAAAAAAAAATTTTTTTTTTTTTTTTTEEEEEEEEEE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

// THIS ONE IS FOR CEASER CIPHER ENCRYPTION
#include <stdio.h>
#include <ctype.h>

void encrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}


// THIS ONE IS FOR CEASER CIPHER DECRYPTION
#include <stdio.h>
#include <ctype.h>

void decode(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base - key + 26) % 26 + base;
        }
    }
}

// THIS ONE IS FOR BOOK ENCRYPTION

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_BOOK_TITLE 50
#define ALPHABET_SIZE 26

int findPositionInBook(FILE *file, char targetChar, int *letterPositions) {
    int position = 0;
    char word[MAX_BOOK_TITLE];

    while (fscanf(file, "%s", word) == 1) {
        position++;

        char firstChar = toupper(word[0]);

        if (firstChar == targetChar && letterPositions[firstChar - 'A'] < position) {
            return position;
        }
    }

    return -1;
}

void resetFilePosition(FILE *file) {
    fseek(file, 0, SEEK_SET);
}

// THIS ONE IS ENCRYPTION USING PLAYFAIR




