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
char* generate_cipher_alphabet(const char* keyword) {
    char* cipher_alphabet = (char*)malloc(ALPHABET_SIZE + 1);
    int keyword_length = strlen(keyword);
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

char* encrypt(const char* plaintext, const char* keyword) {
    char* cipher_alphabet = generate_cipher_alphabet(keyword);
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

char* decrypt(const char* ciphertext, const char* keyword) {
    char* cipher_alphabet = generate_cipher_alphabet(keyword);
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

void railRoadCipherEncryption(char* plainText, int rails) {
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

void railRoadCipherDecryption(char* encoded_message, int rails) {
    int len = strlen(encoded_message);
    char fence[len][rails];

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < rails; j++) {
            fence[i][j] = 0;
        }
    }

    int rail = 0;
    int direction = 1;

    // Fill the fence with placeholders
    for (int i = 0; i < len; i++) {
        fence[i][rail] = 1;  // Using 1 as a placeholder for filled cells
        rail += direction;

        if (rail == 0 || rail == rails - 1) {
            direction = -direction;
        }
    }

    // Fill the fence with the encoded message
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

// Charlie's ---------------------------------------------------------------

//Vigenere Cipher
int getShift(const char *key, int position, bool encrypt) {
    int keyLength = strlen(key);

    if (encrypt) {
        return tolower(key[position % keyLength]) - 'a';
    } else {
        return -(tolower(key[position % keyLength]) - 'a') + 26;
    }
}

void vigenereEncrypt(char *message, const char *key, bool encrypt) {

    for (int i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            int shift = getShift(key, i, encrypt);

            if (isupper(message[i])) {
                message[i] = (message[i] - 'A' + shift) % 26 + 'A';
            } else {
                message[i] = (message[i] - 'a' + shift) % 26 + 'a';
            }
        }
    }
}

//Morse Code
void textToMorse(const char *text) {
    const char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-",
                                "..-", "...-", ".--", "-..-", "-.--", "--..",
                                ".----", "..---", "...--", "....-", ".....",
                                "-....","--...", "---..", "----.", "-----" };


    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = tolower(text[i]);

        if (isalpha(currentChar)) {
            printf("%s ", morseCodes[currentChar - 'a']);
        } else if (isdigit(currentChar)) {
            printf("%s ", morseCodes[currentChar - '0' + 25]);
        } else {
            printf("%c ", currentChar);
        }
    }
    printf("\n");
}

void morseToText(const char *code) {
    const char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-",
                                "..-", "...-", ".--", "-..-", "-.--", "--..",
                                "-----", ".----", "..---", "...--", "....-", ".....",
                                "-....","--...", "---..", "----." };

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == ' ') {
            printf(" ");
            continue;
        }

        char currentCodeLetter[6];
        int j = 0;
        while (code[i] != ' ' && code[i] != '\0') {
            currentCodeLetter[j++] = code[i++];
        }
        currentCodeLetter[j] = '\0';
        if (code[i] == '\0') {
            i--;
        }

        int currentMorseIndex = -1;
        for (int k = 0; k < sizeof(morseCodes) / sizeof(morseCodes[0]); k++) {
            if (strcmp(currentCodeLetter, morseCodes[k]) == 0) {
                currentMorseIndex = k;
            }
        }

        if (currentMorseIndex == -1) {
            printf("%c", code[i-1]);
            continue;
        }

        if (currentMorseIndex < 26) {
            printf("%c", currentMorseIndex + 'a');
        } else {
            printf("%c", currentMorseIndex + '0' - 26);
        }

    }
    printf("\n");
}
//Fractionated Morse Code
void fractionatedMorse(const char *text) {
    const char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-",
                                "..-", "...-", ".--", "-..-", "-.--", "--.."};

    const char *fractionatedCodes[] = {"...", "..-", "..|", ".-.", ".--", ".-|", ".|.",
                                       ".|-", ".||", "-..", "-.-", "-.|", "--.", "---",
                                       "--|", "-|.", "-|-", "-||", "|..", "|.-",
                                       "|.|", "|-.", "|--", "|-|", "||.", "||-"};


    char morseText[500] = "";
    char fractionatedText[100] = "";

    for (int i = 0; text[i] != '\0'; i++) {
        char currentChar = tolower(text[i]);

        if (isalpha(currentChar)) {
            strcat(morseText, morseCodes[currentChar - 'a']);
            strcat(morseText, "|");
        } else if (isspace(currentChar)) {
            strcat(morseText, "|");
        }
    }
    strcat(morseText, "\0");
    printf("\n%s\n", morseText);

    if (strlen(morseText) % 3 == 2) {
        strcat(morseText, ".");
    } else if (strlen(morseText) % 3 == 1) {
        strcat(morseText, ".-");
    }


    int fractionatedIndex = 0;
    for (int i = 0; i < strlen(morseText); i += 3) {
        char fractionatedCharacter[4];
        for (int k = 0; k < 3; k++) {
            fractionatedCharacter[k] = morseText[i + k];
        }
        fractionatedCharacter[3] = '\0';
        for (int j = 0; j < sizeof(fractionatedCodes) / sizeof(fractionatedCodes[0]); j++) {
            if (strcmp(fractionatedCharacter, fractionatedCodes[j]) == 0) {
                fractionatedText[fractionatedIndex] = 'a' + j;
                fractionatedIndex++;
            }
        }
    }

    printf("%s", fractionatedText);
}

void unfractionatedMorse(const char *code) {
    const char *morseCodes[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                                "....", "..", ".---", "-.-", ".-..", "--", "-.",
                                "---", ".--.", "--.-", ".-.", "...", "-",
                                "..-", "...-", ".--", "-..-", "-.--", "--.."};

    const char *fractionatedCodes[] = {"...", "..-", "..|", ".-.", ".--", ".-|", ".|.",
                                       ".|-", ".||", "-..", "-.-", "-.|", "--.", "---",
                                       "--|", "-|.", "-|-", "-||", "|..", "|.-",
                                       "|.|", "|-.", "|--", "|-|", "||.", "||-"};


    char morseCodeText[100] = "";
    char fractionatedCodeText[500] = "";

    for (int i = 0; code[i] != '\0'; i++) {
        int fractionatedMorse = (int) code[i];
        strcat(fractionatedCodeText, fractionatedCodes[fractionatedMorse - 'a']);
    }

    for (int i = 0; i < strlen(fractionatedCodeText); i++) {
        char currentCodeLetter[5];
        int j = 0;
        while (fractionatedCodeText[i] != '|' && fractionatedCodeText[i] != '\0') {
            currentCodeLetter[j++] = fractionatedCodeText[i++];
        }
        currentCodeLetter[j] = '\0';
        if (fractionatedCodeText[i] == '\0') {
            i--;
        }

        for (int k = 0; k < sizeof(morseCodes) / sizeof(morseCodes[0]); k++) {
            if (strcmp(currentCodeLetter, morseCodes[k]) == 0) {
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

    printf("%s", morseCodeText);
}

// Skytale

void skytaleEncrypt(char *message, int key) {
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

void skytaleDecrypt(char *message, int key) {
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

    // Print the decrypted message
    printf("Decrypted Message: ");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < key; j++) {
            printf("%c", matrix[i][j]);
        }
    }
    printf("\n");
}


