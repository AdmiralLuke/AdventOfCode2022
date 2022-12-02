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

int main() {
    FILE* input = getFile("input.txt");
    char* line = getNextLine(input, 10);
    
    int i = 0;

    int tmpCalories = 0;
    int highestCalories = 0;
    int* calories = malloc(sizeof(int) * 256);

    while (line != NULL) {
        if (line[0] == '\n') {
            i++;
            if (tmpCalories > highestCalories) {
                highestCalories = tmpCalories;
            }
            printf("Elf Nr %d has %d\n",i, tmpCalories); 
            calories[i] = tmpCalories;
            tmpCalories = 0;
        } else {
            tmpCalories += atoi(line);
        }
        
        free(line);
        line = getNextLine(input, 256);
    } 

    int second_elf = 0;
    int third_elf = 0;
    // slow and dirty
    for (int i = 0; i < 256; i++) {
        if (calories[i] == highestCalories) {
            calories[i] = 0;
        }
        if (calories[i] > second_elf) {
            printf("%d is higher then %d\n", calories[i], second_elf);
            second_elf = calories[i];
        }
    }

    for (int i = 0; i < 256; i++) {
        if (calories[i] == second_elf) {
            calories[i] = 0;
        }
        if (calories[i] > third_elf) {
            third_elf = calories[i];
        }
    }

    printf("\nHighestCal: %d", highestCalories);

    printf("\n%d + %d + %d = %d",highestCalories, second_elf, third_elf, highestCalories + second_elf + third_elf);
    free(calories);
    fclose(input);
    return -1;
}