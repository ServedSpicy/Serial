#!/bin/sh

clear

base="$(dirname -- $(readlink -fn -- "$0"; echo x))/.."
build="${base}/Build"
source="${base}/Source"
test="${base}/Test"

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
    -D'Testing true'            \
    $source/Serial.cpp          \
    -fPIC                       \
    -c


Objects="${build}/Serial.o ${build}/Test.o"

g++                                     \
    -I/usr/include/libserial            \
    -I"${base}/Source"                  \
    -fmodules-ts "${test}/C++/Test.cpp" \
    -std=c++20                          \
    -o "${build}/Test.o"                \
    -c


echo ""
echo ""
echo "Compiling Binary"
echo ""
echo ""


g++ $Objects        \
    -o $build/App   \
    -lserial


echo ""
echo ""
echo "Testing"
echo ""
echo ""


$build/App
