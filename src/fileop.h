//
// Created by Shaq on 25.04.2016.
//

#ifndef STEGOINC_FILEOP_H
#define STEGOINC_FILEOP_H

#include <stdio.h>
#include <stdlib.h>

char* loadFile(const char* filename);
bool saveFile(const char *filename, char *text);
void printBuffer(char* buffer);

#endif //STEGOINC_FILEOP_H
