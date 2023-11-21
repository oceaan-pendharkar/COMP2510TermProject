//Oceaan's encoding and decoding functions
char * decode64Bit (char * stringToDecode);
char * encode64Bit (char * stringToEncode);
void complexSubstitutionDecode (char * stringToDecode, char * key);
char * complexSubstitutionEncode (char * stringToEncode);
char * simpleSubstitutionDecode(char * stringToDecode);
char * simpleSubstitutionEncode (char * stringToEncode);

// Kate 3 encoding and 1 decoding functions
void encrypt(char message[], int key);
void decode(char message[], int key);
int findPositionInBook(FILE *file, char targetChar, int *letterPositions);
