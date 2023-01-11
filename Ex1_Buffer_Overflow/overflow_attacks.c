/* Demos of buffer overflow attacks */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define BUFFERSIZE 16
#define OVERSIZE 5

void unlimited_BO(char *mal_input){
    // Initialize a memory are containing fixed 256 bytes
    char buffer[BUFFERSIZE];

    // un-checked input string
    strcpy(buffer, mal_input);
}

void off_by_one_BO(char *mal_input){
    char buffer[BUFFERSIZE];

    // using 'less than or equal to' instead of 'less than'
    // by mistake
    for (unsigned int i = 0; i <= BUFFERSIZE; i++){
        buffer[i] = mal_input[i];
    }
}

void heap_overflow(){
    
    char *buffer = (char*) malloc(16);
    char *malicious_input = (char*) malloc(16);
    unsigned long diff = (unsigned long)buffer - (unsigned long)malicious_input;
    printf("Diff: %lu bytes\n", diff);

    strcpy(buffer, "AAAAAAAAAAAAAAA");
    printf("Buffer before Heap Overflow: \t%s\n", buffer);

    memset(malicious_input, 'P', (unsigned int)(diff));
    printf("Buffer after Heap Overflow: \t%s\n", buffer);
}

void good_function(const char* foobar){
    printf("Say: %s\n", foobar);
}

void funcptr_overflow(char* valid_input, char* mal_input){
    char buffer[BUFFERSIZE];
    void (*funcptr)(const char* foobar);

    funcptr = good_function;
    strcpy(buffer, mal_input);
    (*funcptr)(valid_input);
}

void printf_vul(char* mal_input){
    // char buffer[BUFFERSIZE];

    printf(mal_input);
}

int main(int argc, char** argv){
    char buffer[BUFFERSIZE];

    // printf("%s", argv[1]);
    // off_by_one_BO(argv[1]);
    // unlimited_BO(argv[1]);
    // heap_overflow();

    
    strncpy(buffer, argv[1], 15);
    printf_vul(buffer);

    return 0;
}