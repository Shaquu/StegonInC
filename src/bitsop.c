//
// Created by Shaq on 25.04.2016.
//

#include <string.h>
#include <math.h>
#include "bitsop.h"

void setBit(unsigned char* c, unsigned index){ *c |= 1 << index; }
void clearBit(unsigned char* c, unsigned index){ *c  &= ~(1 << index); }
unsigned char checkBit(unsigned char c, unsigned index){ return (c >> index) & 1;}

void getBits(unsigned char c, unsigned char* to){
    unsigned j = 0;
    signed i;
    for(i = 7; i >= 0; i--){
        to[j]=bitN(c, i);
        j++;
    }
}

void printBits(unsigned char c){
    signed i;
    for(i = 7; i >= 0; i--){
        printf("%d", bitN(c, i));
    }
}

void clearBits(ImageData *data){
    unsigned x, y, z;
    unsigned temp = 0;
    unsigned height = data->height;
    unsigned width = data->width;

    for(y = 0; y < height; y++)
        for(x = 0; x < width; x++)
            for(z = 0; z < 4; z++)
                clearBit(&data->image[temp++], 0);
}

void readBits(ImageData *data, char* bitsToRead){
    unsigned x, y, z, temp = 0;
    size_t height = data->height, width = data->width;

    for(y = 0; y < height; y++)
        for(x = 0; x < width; x++)
            for(z = 0; z < 4; z++){
                bitsToRead[temp] = checkBit(data->image[temp], 0);
                temp++;
            }

}

void seedBits(ImageData *data, size_t bitsSize, unsigned char* bitsToWrite){
    unsigned x, y, z, temp = 0;
    bool tempBit = 0;

    size_t height = data->height, width = data->width;
    bool stop = false;

    for(y = 0; y < height && !stop; y++)
        for(x = 0; x < width && !stop; x++)
            for(z = 0; z < 4 && !stop; z++){
                tempBit = bitsToWrite[temp];
                if(tempBit) setBit(&data->image[temp], 0);
                /*printf("%d %d\n", mod(temp, 8), tempBit);

                if(mod(temp, 8) == 8) puts("");*/

                temp++;
                if(temp >= bitsSize) stop = true;
            }

}

void bufferToBits(char* buffer, size_t bufferSize, unsigned char* bitsToWrite, size_t bitsSize){
    unsigned char* tempChar = (unsigned char*) malloc (sizeof (unsigned char*) * 8);
    unsigned x, y, temp;
    temp = 0;
    for(y = 0; y < bufferSize; y++){
        getBits(buffer[y], tempChar);
        //printf("%c = ", buffer[y]);
        for(x = 0; x < 8; x++){
            bitsToWrite[temp] = tempChar[x];
            //printf("%d", bitsToWrite[temp]);
            temp++;
        }
        //puts("");
    }
    free(tempChar);
}

int mod(int x, int y) {
    int r = x%y;
    return (r<0?r+y:r);
}

unsigned bin2char(char* bits, size_t bitSize, char* buffer)
{
    unsigned x, y = 0;
    //char c;
    char data[8];
    for(x = 0; x < bitSize; x++){
        if(bits[x] != '0' && bits[x] != 0)
            data[mod(x, 8)] = '1';
        else
            data[mod(x, 8)] = '0';

        //printf("%d", bits[x]);
        if(mod(x, 8) + 1 == 8){
            //printf("%s", data);
            //printf(" %ld \n", strtol(data, (char **)NULL, 2));
            //c = (char)strtol(data, (char **)NULL, 2);

            if(strtol(data, (char **)NULL, 2) == 0)
                break;

            buffer[y++] = (char)strtol(data, (char **)NULL, 2);
            //printf("%c ", buffer[y]);
            //y++;
        }
    }
    return y;
    //printf("%s ", buffer);
}