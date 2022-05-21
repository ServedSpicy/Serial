#!/bin/sh

clear

base="$(dirname -- $(readlink -fn -- "$0"; echo x))/"
build="${base}/Tools/Build"
test="${base}/Test/Deno/Test.js"

$build

deno run                     \
    --allow-net              \
    --allow-ffi              \
    --unstable               \
    --allow-read=/dev/,$base \
    $test
