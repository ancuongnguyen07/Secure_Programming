/* Demos of buffer overflow attacks */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define FIXED_SIZE 256
#define OVERSIZE 5

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

void heap_overflow(){
    
    char *buffer = (char*) malloc(16);
    char *malicious_input = (char*) malloc(16);
    unsigned long diff = (unsigned long)buffer - (unsigned long)malicious_input;
    printf("Diff: %lu bytes\n", diff);

    strcpy(buffer, "AAAAAAAAAAAAAAA");
    printf("Buffer before Heap Overflow: \t%s\n", buffer);

    memset(malicious_input, 'P', (unsigned int)(diff*OVERSIZE));
    printf("Buffer after Heap Overflow: \t%s\n", buffer);
}

int main(){
    // off_by_one_BO();
    // unlimited_BO();
    // heap_overflow();

    return 0;
}