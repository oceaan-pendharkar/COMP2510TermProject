//This is where we will include our tests to show how it works with the ciphers.h file :)
#include <stdio.h>
#include "ciphers.h"

int main() {
    char * encodedString = encode64Bit("green apple");
    printf("%s", encodedString);
    return 0;
}
