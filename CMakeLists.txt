cmake_minimum_required(VERSION 3.5)
project(StegoInC)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -Werror")

set(SOURCE_FILES main.c main.h src/lodepng.c src/lodepng.h src/imagedata.c src/imagedata.h src/encode.c src/encode.h src/decode.c src/decode.h src/bitsop.c src/bitsop.h src/fileop.c src/fileop.h)
add_executable(StegoInC ${SOURCE_FILES})