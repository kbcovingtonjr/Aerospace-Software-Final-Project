#!/bin/bash
# 
# This script profiles the serial portion of the code.

echo "Compiling, linking, etc..."
make profile
./matMult $1
gprof matMult gmon.out > analysis.txt
echo ""

