#include <stdbool.h>

//Oceaan's encoding and decoding functions
char * decode64Bit (char * stringToDecode);
char * encode64Bit (char * stringToEncode);
void complexSubstitutionDecode (char * stringToDecode, char * key);
char * complexSubstitutionEncode (char * stringToEncode);
char * simpleSubstitutionDecode(char * stringToDecode);
char * simpleSubstitutionEncode (char * stringToEncode);


// Kate 3 encoding and 2 decoding functions
void encodePlayfair(char str[], char key[]);
void CeasarDecode(char message[], int key);
void ceasarEncrypt(char message[], int key);
int BookCipherEncode(FILE *file, char targetChar, int *letterPositions);
void resetFilePosition(FILE *file);
int bookCipherDecode(FILE *file, int targetPosition, char *decodedLetter);



// Viv's
void railRoadCipherEncryption(char* plainText, int rails);
void railRoadCipherDecryption(char* encoded_message, int rails);
void simpleXORCipher(char* message, const char* key);
void scytaleEncrypt(char *message, int key);
void scytaleDecrypt(char *message, int key);

// Michael
void atbashCipher(char *text);
void rot13Cipher(char *text);
char *textToBinary(const char *text);
char* generateCipherAlphabet(const char* keyword);

char* cipherAlphabetEncrypt(const char* plaintext, const char* keyword);
char* cipherAlphabetDecrypt(const char* ciphertext, const char* keyword);
// Charlie's functions
void vigenereEncrypt(char *message, const char *key, bool encrypt);
void textToMorse(const char *text);
void morseToText(const char *code);
void fractionatedMorse(const char *text);
void unfractionatedMorse(const char *code);
//>>>>>>> origin/main
