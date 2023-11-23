#include <stdbool.h>

//Oceaan's encoding and decoding functions
char * decode64Bit (char * stringToDecode);
char * encode64Bit (char * stringToEncode);
void complexSubstitutionDecode (char * stringToDecode, char * key);
char * complexSubstitutionEncode (char * stringToEncode);
char * simpleSubstitutionDecode(char * stringToDecode);
char * simpleSubstitutionEncode (char * stringToEncode);
// Viv's
void railRoadCipherEncryption(char* plainText, int rails);
void railRoadCipherDecryption(char* encoded_message, int rails);
void simpleXORCipher(char* message, const char* key);
// Michael
void atbashCipher(char *text);
void rot13Cipher(char *text);
char *textToBinary(const char *text);
// Charlie's functions
void vigenereEncrypt(char *message, const char *key, bool encrypt);
void textToMorse(const char *text);
void morseToText(const char *code);
void fractionatedMorse(const char *text);
void unfractionatedMorse(const char *code);
