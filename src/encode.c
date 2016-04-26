//
// Created by Shaq on 25.04.2016.
//

#include "encode.h"

bool readMsgFromFile(char* src, char* destText){
    printf("\n====================read message from png file====================\n");
    printf("1. Decode start. Load pixels from %s\n\n", src);

    ImageData* data = decode(src);
    if(data->error){
        printf("2. Decode error %u: %s\n\n", data->error, lodepng_error_text(data->error));
        return false;
    }

    size_t height = data->height, width = data->width;
    size_t bitSize = height * width * 4;
    char* bitsToRead = (char*) calloc (bitSize, sizeof (char*));


    printf("2. Reading last bits\n\n");
    readBits(data, bitsToRead);

    printf("3. Reading chars from bits\n");
    char* buffer = (char*) calloc (bitSize/8, sizeof (char*));
    size_t newSize = bin2char(bitsToRead, bitSize, buffer);
    buffer = realloc(buffer, sizeof (char*) * newSize);

    printf("\n4. Text length: %zu\n\n", newSize);

    printf("\n5. Saving file %s", destText);
    bool saved = saveFile(destText, buffer);
    if(saved){
        printf("\n   Saved!\n\n");
    } else {
        printf("\n   Couln't save!\n\n");
        return false;
    }

    return true;
}

void encode(ImageData* data)
{
    data->error = lodepng_encode32_file(data->filename, data->image, data->width, data->height);;
}