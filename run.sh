#!/bin/sh

CURRENT_DIR=/home/siro53/kyo-pro/ahc
SOURCE=$1
INPUT=$CURRENT_DIR/tools/$2
OUTPUT=$CURRENT_DIR/output.txt

g++ -std=c++20 -O2 -DDEBUG -Wall -Wextra $SOURCE
cd tools
cargo run -r --bin tester $CURRENT_DIR/a.out < $INPUT > $OUTPUT
cat $OUTPUT | clip.exe