//
// Created by Shaq on 25.04.2016.
//

#include "decode.h"

bool hideMsgInFile(char *src, char *srcText, char *dest) {
    printf("\n====================hide message in png file====================\n");
    printf("1. Decode start. Load pixels from %s\n\n", src);

    ImageData *data = decode(src);
    if (data->error) {
        printf("2. Decode error %u: %s\n\n", data->error, lodepng_error_text(data->error));
        return false;
    }

    data->filename = dest;

    //Clear youngest bits on pixels
    printf("2. Clearing last bits\n\n");
    clearBits(data);

    //load string from txt file
    char *buffer = loadFile(srcText);
    size_t bufferSize = strlen(buffer);
    printf("3. Text to hide length: %zu\n\n", bufferSize);

    size_t bitsSize = bufferSize * 8;

    unsigned char *bitsToWrite = (unsigned char *) malloc(sizeof(unsigned char *) * bitsSize);
    if (!bitsToWrite)
        return false;

    printf("4. Setting last bits\n\n");
    bufferToBits(buffer, bufferSize, bitsToWrite, bitsSize);

    /*unsigned y;
    for(y = 0; y < bitsSize; y++){
        printf("%d", bitsToWrite[y]);
    }
    puts("");*/

    if (bitsSize / 3 > data->width * data->height) {
        printf("5. Not enough pixels to hide your message\n\n");
        return false;
    }

    seedBits(data, bitsSize, bitsToWrite);

    encode(data);
    if (data->error) {
        printf("5. Encode error %u: %s\n\n", data->error, lodepng_error_text(data->error));
        return false;
    }
    printf("5. Encode finished. File saved.\n\n");

    if (buffer)
        free(buffer);
    if (data) {
        free(data->image);
        free(data);
    }
    if (bitsToWrite)
        free(bitsToWrite);

    printf("6. Data freed.\n\n");

    return true;
}


bool hideFileInFile(char *src, char *srcImage, char *dest){

    printf("\n====================hide png file in png file====================\n");
    printf("1. Decode start. Load pixels from %s\n\n", src);

    ImageData *data = decode(src);
    if (data->error) {
        printf("2. Decode error %u: %s\n\n", data->error, lodepng_error_text(data->error));
        return false;
    }

    data->filename = dest;

    //Clear youngest bits on pixels
    printf("2. Clearing last bits\n\n");
    clearBits(data);

    printf("3.1 Decode start. Load pixels from %s\n\n", srcImage);

    ImageData *data2 = decode(srcImage);
    if (data2->error) {
        printf("3.2. Decode error %u: %s\n\n", data2->error, lodepng_error_text(data2->error));
        return false;
    }

    size_t bufferSize = strlen(srcImage);
    printf("3.2 Png file to hide length: %zu\n\n", bufferSize);


    //STOP
    /*size_t bitsSize = bufferSize * 8;

    unsigned char *bitsToWrite = (unsigned char *) malloc(sizeof(unsigned char *) * bitsSize);
    if (!bitsToWrite)
        return false;

    printf("4. Setting last bits\n\n");
    bufferToBits(buffer, bufferSize, bitsToWrite, bitsSize);

    if (bitsSize / 3 > data->width * data->height) {
        printf("5. Not enough pixels to hide your message\n\n");
        return false;
    }

    seedBits(data, bitsSize, bitsToWrite);

    encode(data);
    if (data->error) {
        printf("5. Encode error %u: %s\n\n", data->error, lodepng_error_text(data->error));
        return false;
    }
    printf("5. Encode finished. File saved.\n\n");

    if (buffer)
        free(buffer);
    if (data) {
        free(data->image);
        free(data);
    }
    if (bitsToWrite)
        free(bitsToWrite);

    printf("6. Data freed.\n\n");
    */
    return true;
}

ImageData *decode(char *filename) {
    unsigned error;
    unsigned char *image;
    unsigned width, height;

    error = lodepng_decode32_file(&image, &width, &height, filename);
    if (error)
        printf("error %u: %s\n", error, lodepng_error_text(error));

    ImageData *data = malloc(sizeof(ImageData));
    data->filename = filename;
    data->width = width;
    data->height = height;
    data->image = image;
    data->error = error;

    return data;
}