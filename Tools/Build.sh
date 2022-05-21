#!/bin/sh

base="$(dirname -- $(readlink -fn -- "$0"; echo x))/.."
build="${base}/Build"
source="${base}/Source"
test="${base}Test"

rm -r $build
mkdir $build


echo ""
echo ""
echo "Compiling Object Files"
echo ""
echo ""


g++                             \
    -I/usr/include/libserial    \
    -o $build/Serial.o          \
    -fmodules-ts                \
    -std=c++20                  \
    -fPIC                       \
    -c                          \
    $source/Serial.cpp


echo ""
echo ""
echo "Compiling Library"
echo ""
echo ""


g++                             \
    $build/Serial.o             \
    -o $build/Serial.so         \
    -shared                     \
    -W                          \
    -lserial

g++                             \
    $build/Serial.o             \
    -o $build/Serial.dylib      \
    -shared                     \
    -W                          \
    -lserial

g++                             \
    $build/Serial.o             \
    -o $build/Serial.dll        \
    -shared                     \
    -W                          \
    -lserial
