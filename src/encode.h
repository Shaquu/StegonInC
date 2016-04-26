//
// Created by Shaq on 25.04.2016.
//

#ifndef STEGOINC_ENCODE_H
#define STEGOINC_ENCODE_H

#include <stdio.h>
#include <stdbool.h>
#include "imagedata.h"
#include "lodepng.h"
#include "decode.h"

void encode(ImageData* data);
bool readMsgFromFile(char* src, char* destText);

#endif //STEGOINC_ENCODE_H
