#!/bin/bash
gcc -Wall -pedantic -Wextra -Werror -pedantic -c *.c
ar -rc liball.a *.o
ranlib liball.a
