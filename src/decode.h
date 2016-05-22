//
// Created by Shaq on 25.04.2016.
//

#ifndef STEGOINC_DECODE_H
#define STEGOINC_DECODE_H

#include <stdio.h>
#include <stdbool.h>
#include "imagedata.h"
#include "lodepng.h"
#include "bitsop.h"
#include "fileop.h"
#include "encode.h"

// Decode png file to rgba pixels array
bool hideMsgInFile(char *src, char *srcText, char *dest);

ImageData *decode(char *filename);

#endif //STEGOINC_DECODE_H
