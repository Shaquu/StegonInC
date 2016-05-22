//
// Created by Shaq on 25.04.2016.
//

#ifndef STEGOINC_IMAGEDATA_H
#define STEGOINC_IMAGEDATA_H

#include <stdlib.h>

typedef struct ImageDataTag {
    unsigned char *image;
    unsigned width, height;
    char *filename;
    unsigned error;
} ImageData;

#endif //STEGOINC_IMAGEDATA_H
