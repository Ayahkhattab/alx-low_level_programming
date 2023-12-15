#!/bin/bash
gcc -fpIc -c *.c
gcc -shared *.c -o liball.so
