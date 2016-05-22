//
// Created by Shaq on 25.04.2016.
//

#ifndef STEGOINC_BITSOP_H
#define STEGOINC_BITSOP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "imagedata.h"

#define bitN(arg, n) (((arg)>>(n))&1)

void setBit(unsigned char *c, unsigned index);

void clearBit(unsigned char *c, unsigned index);

void getBits(unsigned char c, unsigned char *to);

unsigned char checkBit(unsigned char c, unsigned index);

void clearBits(ImageData *data);

void seedBits(ImageData *data, size_t bitsSize, unsigned char *bitsToWrite);

void readBits(ImageData *data, char *bitsToRead);

void bufferToBits(char *buffer, size_t bufferSize, unsigned char *bitsToWrite, size_t bitsSize);

int mod(int x, int y);

unsigned bin2char(char *bits, size_t bitSize, char *buffer);

#endif //STEGOINC_BITSOP_H
