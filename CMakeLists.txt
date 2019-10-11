cmake_minimum_required(VERSION 3.15)
project(VigenereCipher C)

set(CMAKE_C_STANDARD 99)

add_executable(VigenereCipher main.c operations.c operations.h)