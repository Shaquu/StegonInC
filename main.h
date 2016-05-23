//
// Created by Shaq on 25.04.2016.
//

#ifndef STEGOINC_MAIN_H
#define STEGOINC_MAIN_H

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#include <stdio.h>
#include "src/decode.h"

int main();

void appMenu();

void clear();

void printHeader();

#endif //STEGOINC_MAIN_H
