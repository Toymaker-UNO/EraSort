#!/bin/bash

g++ -W -Wall -I ./hpp ./cpp/main.cpp -o EraSort.exe
./EraSort.exe
#rm -rf ./EraSort.exe