//
// Created by Shaq on 25.04.2016.
//

#include <stdbool.h>
#include "fileop.h"

char *loadFile(const char *filename) {
    char *buffer;
    long length = 0;
    FILE *f = fopen(filename, "rb");

    if (f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if (buffer) {
            fread(buffer, 1, length, f);
        }
        fclose(f);
    }
    buffer[length + 1] = '\0';
    return buffer;
}

void printBuffer(char *buffer) {
    printf("%s\n", buffer);
}

bool saveFile(const char *filename, char *text) {
    FILE *f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        return false;
    }

    fprintf(f, "%s\n", text);

    fclose(f);
    return true;
}

