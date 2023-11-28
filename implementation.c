//this is where we will put the implementations of all our functions.
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//constants
#define ALPHABET_SIZE 26
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

// 3 Atbash Ciper
void atbashCipher(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Check if the current character is an alphabet letter
        if (isalpha(text[i])) {
            // Determine if the letter is uppercase or lowercase
            char case_diff = isupper(text[i]) ? 'A' : 'a';

            // Apply Atbash cipher to the current letter
            text[i] = 'Z' - (text[i] - case_diff);
        }
    }
}

//4 Binary Enconding
char *textToBinary(const char *text) {
    int len = strlen(text);
    char *binaryResult = (char *)malloc((len * 8 + 1) * sizeof(char));
    if (binaryResult == NULL) {
        fprintf(stderr, "Memory allocation error\n");
    }
    int index = 0;
    for (int i = 0; i < len; i++) {
        char currentChar = text[i];
        // Convert each character to its binary representation
        for (int j = 7; j >= 0; j--) {
            binaryResult[index++] = ((currentChar >> j) & 1) + '0';
        }
        // Add spaces between binary representations of different characters
        binaryResult[index++] = ' ';
    }
    binaryResult[index] = '\0';
    return binaryResult;
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

// 7 ROT13
void rot13Cipher(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char case_diff = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - case_diff + 13) % 26 + case_diff;
        }
    }
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

//9. Keyword Cipher
char* generateCipherAlphabet(const char* keyword) {
    char* cipher_alphabet = (char*)malloc(ALPHABET_SIZE + 1);
    int keyword_length = strlen(keyword);
    if (cipher_alphabet == NULL) {
        fprintf(stderr, "Memory allocation error");
    }
    int i, j;
    for (i = 0; i < keyword_length; ++i) {
        cipher_alphabet[i] = toupper(keyword[i]);
    }
    for (i = keyword_length, j = 'A'; i < ALPHABET_SIZE; ++i, ++j) {
        while (strchr(keyword, j) != NULL) {
            ++j;
        }
        cipher_alphabet[i] = j;
    }
    cipher_alphabet[ALPHABET_SIZE] = '\0';
    return cipher_alphabet;
}

char* cipherAlphabetEncrypt(const char* plaintext, const char* keyword) {
    char* cipher_alphabet = generateCipherAlphabet(keyword);
    int text_length = strlen(plaintext);
    char* ciphertext = (char*)malloc(text_length + 1);
    for (int i = 0; i < text_length; ++i) {
        if (isalpha(plaintext[i])) {
            int index = toupper(plaintext[i]) - 'A';
            ciphertext[i] = cipher_alphabet[index];
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[text_length] = '\0';
    free(cipher_alphabet);
    return ciphertext;
}

char* cipherAlphabetDecrypt(const char* ciphertext, const char* keyword) {
    char* cipher_alphabet = generateCipherAlphabet(keyword);
    int text_length = strlen(ciphertext);
    char* plaintext = (char*)malloc(text_length + 1);

    for (int i = 0; i < text_length; ++i) {
        if (isalpha(ciphertext[i])) {
            char* index = strchr(cipher_alphabet, toupper(ciphertext[i]));
            plaintext[i] = 'A' + (int)(index - cipher_alphabet);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[text_length] = '\0';
    free(cipher_alphabet);
    return plaintext;
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
/////////////////////////Viv

void railFenceCipherEncryption(char* plainText, int rails) {
    int len = strlen(plainText);
    char fence[len][rails];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < rails; j++) {
            fence[i][j] = 0;
        }
    }

    int rail = 0;
    int direction = 1;

    for (int i = 0; i < len; i++) {
        fence[i][rail] = plainText[i];
        rail += direction;

        if (rail == 0 || rail == rails - 1) {
            direction = -direction;
        }
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (fence[j][i] != 0) {
                plainText[index++] = fence[j][i];
            }
        }
    }
}

void railFenceCipherDecryption(char* encoded_message, int rails) {
    int len = strlen(encoded_message);
    char fence[len][rails];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < rails; j++) {
            fence[i][j] = 0;
        }
    }

    int rail = 0;
    int direction = 1;

    for (int i = 0; i < len; i++) {
        fence[i][rail] = 1;
        rail += direction;

        if (rail == 0 || rail == rails - 1) {
            direction = -direction;
        }
    }

    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            if (fence[j][i] == 1) {
                fence[j][i] = encoded_message[index++];
            }
        }
    }


    rail = 0;
    direction = 1;
    for (int i = 0; i < len; i++) {
        encoded_message[i] = fence[i][rail];
        rail += direction;

        if (rail == 0 || rail == rails - 1) {
            direction = -direction;
        }
    }
}

void simpleXORCipher(char* message, const char* key) {
    int len = strlen(message);
    int keyLen = strlen(key);

    for (int i = 0; i < len; i++) {
        message[i] = message[i] ^ key[i % keyLen];
    }
}


void scytaleEncrypt(char *message, int key) {
    int messageLength = strlen(message);
    int numRows = (messageLength + key - 1) / key;

    char matrix[numRows][key];

    int index = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < key; j++) {
            if (index < messageLength) {
                matrix[i][j] = message[index++];
            } else {
                matrix[i][j] = ' ';
            }
        }
    }

    printf("Encrypted Message: ");
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < numRows; j++) {
            printf("%c", matrix[j][i]);
        }
    }
    printf("\n");
}

void scytaleDecrypt(char *message, int key) {
    int messageLength = strlen(message);
    int numRows = (messageLength + key - 1) / key;

    char matrix[numRows][key];

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < key; j++) {
            matrix[i][j] = ' ';
        }
    }

    int index = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < numRows; j++) {
            matrix[j][i] = message[index++];
        }
    }

    printf("Decrypted Message: ");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < key; j++) {
            printf("%c", matrix[i][j]);
        }
    }
    printf("\n");
}




// Charlie's ---------------------------------------------------------------

//Vigenere Cipher
int getVigenereShift(const char *key, int position, bool encrypt) {
    int keyLength = strlen(key);

    if (encrypt) {
        // For encryption, calculate the shift for the current position and convert to lowercase
        return tolower(key[position % keyLength]) - 'a';
    } else {
        // For decryption, calculate the shift for the current position and adjust to ensure positive values
        return -(tolower(key[position % keyLength]) - 'a') + 26;
    }
}

void vigenereEncrypt(char *message, const char *key, bool encrypt) {

    int nonAlphaCounter = 0;
    // Iterate through each character in the message
    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            // Get the Vigenere shift for the current position
            int shift = getVigenereShift(key, i - nonAlphaCounter, encrypt);

            // Encrypt or cipherAlphabetDecrypt the uppercase letter and ensure it wraps around the alphabet
            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + shift) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + shift) % 26 + 'a';
            }
        } else {
            nonAlphaCounter++;
        }
    }
}

//Morse Code
char* getMorseChar(int morseIndex) {
    // Array of Morse code representations for letters (A-Z) and digits (0-9)
    char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-",
                                "..-", "...-", ".--", "-..-", "-.--", "--..",
                                "-----", ".----", "..---", "...--", "....-", ".....",
                                "-....","--...", "---..", "----."};
    return morseCodes[morseIndex];
}


void textToMorse(const char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = tolower(text[i]);

        if (isalpha(currentChar)) {
            printf("%s ", getMorseChar(currentChar - 'a'));
        } else if (isdigit(currentChar)) {
            printf("%s ", getMorseChar(currentChar - '0' + 25));
        } else {
            printf("%c ", currentChar);
        }
    }
    printf("\n");
}

void morseToText(const char *code) {
    // Loop through the input Morse code
    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == ' ') {
            printf(" ");
            continue;
        }

        // Array to store the current Morse code letter
        char currentCodeLetter[6];
        int j = 0;

        // Extract Morse code letter until a space or end of string is encountered
        while (code[i] != ' ' && code[i] != '\0') {
            currentCodeLetter[j++] = code[i++];
        }
        currentCodeLetter[j] = '\0';
        if (code[i] == '\0') {
            i--;
        }

        // Search for the current Morse code letter in the Morse code array
        int currentMorseIndex = -1;
        for (int k = 0; k < 36; k++) {
            if (strcmp(currentCodeLetter, getMorseChar(k)) == 0) {
                currentMorseIndex = k;
            }
        }

        // Check if the Morse code letter was not found
        if (currentMorseIndex == -1) {
            printf("%c", code[i-1]);// Print the character as is
            continue;
        }

        // Print the corresponding letter or digit for the Morse code
        if (currentMorseIndex < 26) {
            printf("%c", currentMorseIndex + 'a');
        } else {
            printf("%c", currentMorseIndex + '0' - 26);
        }

    }
    printf("\n");
}

//Fractionated Morse Code

char* getFractionatedMorseChar(int morseIndex, bool fractionated) {
    char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-",
                                "..-", "...-", ".--", "-..-", "-.--", "--.."};

    char *fractionatedCodes[] = {"...", "..-", "..|", ".-.", ".--", ".-|", ".|.",
                                 ".|-", ".||", "-..", "-.-", "-.|", "--.", "---",
                                 "--|", "-|.", "-|-", "-||", "|..", "|.-",
                                 "|.|", "|-.", "|--", "|-|", "||.", "||-"};

    if (fractionated) {
        return fractionatedCodes[morseIndex];
    } else {
        return morseCodes[morseIndex];
    }
}

void fractionatedMorse(const char *text) {
    // Initialize arrays to store Morse code and fractionated text
    char morseText[500] = "";
    char fractionatedText[100] = "";

    // Loop through each character in the input text
    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = tolower(text[i]);

        if (isalpha(currentChar)) {
            // If the character is an alphabet letter, append its Morse code to morseText
            strcat(morseText, getFractionatedMorseChar(currentChar - 'a', false));
            strcat(morseText, "|"); // Use "|" as a separator between Morse code characters
        } else if (isspace(currentChar)) {
            strcat(morseText, "|");
        }
    }
    strcat(morseText, "\0");
    printf("\n%s\n", morseText);

    // Adjust the Morse code length for encryption adding characters to make it divisible by 3
    if (strlen(morseText) % 3 == 2) {
        strcat(morseText, ".");
    } else if (strlen(morseText) % 3 == 1) {
        strcat(morseText, ".-");
    }


    int fractionatedIndex = 0;
    // Loop through morseText with a step size of 3 to extract Morse code trigrams
    for (int i = 0; i < strlen(morseText); i += 3) {
        char fractionatedCharacter[4];
        for (int k = 0; k < 3; k++) {
            fractionatedCharacter[k] = morseText[i + k];
        }
        fractionatedCharacter[3] = '\0';

        // Match the Morse code triplet to its corresponding alphabet letter
        for (int j = 0; j < 26; j++) {
            if (strcmp(fractionatedCharacter, getFractionatedMorseChar(j, true)) == 0) {
                fractionatedText[fractionatedIndex] = 'a' + j;
                fractionatedIndex++;
            }
        }
    }

    printf("Fractionated Code:\n%s", fractionatedText);
}

void unfractionatedMorse(const char *code) {
    // Initialize arrays to store Morse code and fractionated text
    char morseCodeText[100] = "";
    char fractionatedCodeText[500] = "";

    // Loop through each character in the input code
    for (int i = 0; code[i] != '\0'; i++) {
        int fractionatedMorse = (int) code[i];

        // Append the Fractionated Morse code character to fractionatedCodeText
        strcat(fractionatedCodeText, getFractionatedMorseChar(fractionatedMorse - 'a', true));
    }

    printf("\nMorse Code:\n%s", fractionatedCodeText);

    // Loop through fractionatedCodeText
    for (int i = 0; i < strlen(fractionatedCodeText); i++) {
        char currentCodeLetter[5];
        int j = 0;

        // Extract the Fractionated Morse code letter until a "|" or end of string is encountered
        while (fractionatedCodeText[i] != '|' && fractionatedCodeText[i] != '\0') {
            currentCodeLetter[j++] = fractionatedCodeText[i++];
        }
        currentCodeLetter[j] = '\0';
        if (fractionatedCodeText[i] == '\0') {
            i--;
        }

        // Search for the current Morse code letter in the Morse code array
        for (int k = 0; k < 26; k++) {
            if (strcmp(currentCodeLetter, getFractionatedMorseChar(k, false)) == 0) {
                // Append the deciphered character to morseCodeText
                char decipheredChar = k + 'a';
                morseCodeText[strlen(morseCodeText)] = decipheredChar;
                break;
            }
        }

        if (fractionatedCodeText[i] == '|' && fractionatedCodeText[i + 1] == '|') {
            strcat(morseCodeText, " ");
            i++;
        }
    }

    printf("\nDeciphered Text: \n%s", morseCodeText);
}

//PLayfair cipher

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30

void toLowerCase(char plain[], int ps)
{
    int i = 0;
    for (i = 0; i < ps; i++) {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}

int removeSpaces(char* plainText, int ps)
{
    int i = 0;
    int count = 0;

    for (i = 0; i < ps; i++)
        if (plainText[i] != ' ')
            plainText[count++] = plainText[i];
    plainText[count] = '\0';
    return count;
}

void generateKeyTable(char key[], int ks, char keyT[5][5])
{
    int i, j, k = 0;
    int flag = 0,
            *hashDictionary;

    hashDictionary = (int*)calloc(26, sizeof(int));
    for (i = 0; i < ks; i++) {
        if (key[i] != 'j')
            hashDictionary[key[i] - 97] = 2;
    }
    hashDictionary['j' - 97] = 1;
    i = 0;
    j = 0;

    for (k = 0; k < ks; k++) {
        if (hashDictionary[key[k] - 97] == 2) {
            hashDictionary[key[k] - 97] -= 1;
            keyT[i][j] = key[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }

    for (k = 0; k < 26; k++) {
        if (hashDictionary[k] == 0) {
            keyT[i][j] = (char)(k + 97);
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
}

void search(char keyT[5][5], char characterA, char characterB, int arr[])
{
    int i, j = 0;

    if (characterA == 'j')
        characterA = 'i';
    else if (characterB == 'j')
        characterB = 'i';
    for (i = 0; i < 5; i++) {

        for (j = 0; j < 5; j++) {
            if (keyT[i][j] == characterA) {
                arr[0] = i;
                arr[1] = j;
            }
            else if (keyT[i][j] == characterB) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a) { return (a % 5); }

int prepare(char str[], int ptrs)
{
    if (ptrs % 2 != 0) {
        str[ptrs++] = 'z';
        str[ptrs] = '\0';
    }
    return ptrs;
}

void playfairEncrypt(char str[], char keyT[5][5], int ps)
{
    int i = 0;
    int a[4];
    for (i = 0; i < ps; i += 2) {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        }
        else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void encodePlayfair(char str[], char key[])
{
    char ps;
    char ks;
    char keyT[5][5];

    ks = strlen(key);
    ks = removeSpaces(key, ks);
    toLowerCase(key, ks);

    // Plaintext
    ps = strlen(str);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);

    ps = prepare(str, ps);

    generateKeyTable(key, ks, keyT);

    playfairEncrypt(str, keyT, ps);
}

//// CEASAR DECODE

#include <stdio.h>
#include <ctype.h>

void CeasarDecode(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base - key + 26) % 26 + base;
        }
    }
}

////CEASAR ENCODE

#include <stdio.h>
#include <ctype.h>

void ceasarEncrypt(char message[], int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            message[i] = (message[i] - base + key) % 26 + base;
        }
    }
}

// BOOK CIPHER ENCODE

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_BOOK_TITLE 50
#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 50

int BookCipherEncode(FILE *file, char targetChar, int *letterPositions) {
    int position = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%s", word) == 1) {
        position++;

        char firstChar = toupper(word[0]);

        if (firstChar == targetChar && letterPositions[firstChar - 'A'] < position) {
            return position;
        }
    }

    return -1;
}

void resetFilePositionEncode(FILE *file) {
    fseek(file, 0, SEEK_SET);
}


// BOOK CIPHER DECODE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BOOK_TITLE 50
#define ALPHABET_SIZE 26
#define MAX_FILE_CONTENT 10000

    int bookCipherDecode(FILE *file, int targetPosition, char *decodedLetter) {
        int position = 0;
        char word[MAX_BOOK_TITLE];

        while (fscanf(file, "%s", word) == 1) {
            position++;

            if (position == targetPosition) {
                *decodedLetter = word[0];
                return 1;
            }
        }

        return 0;
    }

    void resetFilePosition(FILE *file) {
        fseek(file, 0, SEEK_SET);
    }






