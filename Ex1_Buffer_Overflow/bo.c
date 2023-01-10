/* Demos of buffer overflow attacks */
#include <stdlib.h>
#include <string.h>

#define FIXED_SIZE 256

void unlimited_BO(){
    // Initialize a memory are containing fixed 256 bytes
    char buffer[FIXED_SIZE];

    // Send to the buffer up to 512 bytes
    for (unsigned int i = 0; i <  512; i++){
        buffer[i] = 'A';
    }
}

void off_by_one_BO(){
    char buffer[FIXED_SIZE];

    // using 'less than or equal to' instead of 'less than'
    // by mistake
    for (unsigned int i = 0; i <= FIXED_SIZE; i++){
        buffer[i] = 'A';
    }
}

int main(int argc, char** argv){
    char buffer[256];
    strcpy(buffer, argv[1]);

    return 0;
}