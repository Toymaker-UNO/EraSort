#!/bin/bash

g++ -W -Wall -I ./hpp ./src/main.cpp -o te.exe
./te.exe /c/Isla_Sorna/ hpp
rm -rf ./te.exe