#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Get the File object
 * 
 * @param path relative path to the File
 * @return FILE* if file existed: File, else: Null
 */
FILE* getFile(char* path) {
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: Couldnt open file %s", path);
        return NULL;
    }
    return fp;
} 

/**
 * @brief Get the Next Line object
 * 
 * @param fp File with read rights
 * @param MAX_LENGTH Max length of bytes which are read per line
 * @return char* line content with length max_length
 */
char* getNextLine(FILE* fp, const unsigned MAX_LENGTH) {
    char* buffer = malloc(sizeof(char) * MAX_LENGTH);
    if (fgets(buffer, MAX_LENGTH, fp)) {
        return buffer;
    } else {
        return NULL;
    }
}
// x -> Rock 1 | y -> Paper 2 | z -> Scissors 3
// loose -> 0 | draw -> 3 | win -> 6
int pointsByRock(char b) {
    switch (b) {
        case 'X' : return 1 + 3;
        case 'Y' : return 2 + 6;
        case 'Z' : return 3; 
        default: printf("smth went wrong...\n");
    }
}

int pointsBySciss(char b) {
    switch (b) {
        case 'X' : return 1 + 6;
        case 'Y' : return 2;
        case 'Z' : return 3 + 3; 
        default: printf("smth went wrong...\n");
    }
}

int pointsByPaper(char b) {
    switch (b) {
        case 'X' : return 1;
        case 'Y' : return 2 + 3;
        case 'Z' : return 3 + 6; 
        default: printf("smth went wrong...\n");
    }
}

// x -> lose | y -> draw | z -> win
int t2_pointsByRock(char b) {
    switch (b) {
        case 'Y' : return 1 + 3;
        case 'Z' : return 2 + 6;
        case 'X' : return 3; 
        default: printf("smth went wrong...\n");
    }
}

int t2_pointsBySciss(char b) {
    switch (b) {
        case 'Z' : return 1 + 6;
        case 'X' : return 2;
        case 'Y' : return 3 + 3; 
        default: printf("smth went wrong...\n");
    }
}

int t2_pointsByPaper(char b) {
    switch (b) {
        case 'X' : return 1;
        case 'Y' : return 2 + 3;
        case 'Z' : return 3 + 6; 
        default: printf("smth went wrong...\n");
    }
}

int main() {
    FILE* input = getFile("input.txt");
    char* line = getNextLine(input, 5);
    
    int sum = 0;
    int t2_sum = 0;
    while (line != NULL) {
        // printf("%c - %c ", line[0], line[2]);
        switch (line[0]) {
            case 'A': 
                sum += pointsByRock(line[2]); 
                t2_sum += t2_pointsByRock(line[2]);
                break;
            case 'B': 
                sum += pointsByPaper(line[2]);
                t2_sum += t2_pointsByPaper(line[2]);
                break;
            case 'C': 
                sum += pointsBySciss(line[2]);
                t2_sum += t2_pointsBySciss(line[2]);
                break;
            default: printf("smth went wrong...\n");
        }
        // printf("%d\n", sum);
        line = getNextLine(input, 5);
    } 

    printf("sum: %d", sum);
    printf("\n t2_sum: %d", t2_sum);

    fclose(input);
    return 1;
}