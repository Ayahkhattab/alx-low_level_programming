#!/bin/bash
gcc -wall -wextra -wextra -werror -pedantic -c *.c
ar rc liball.a *.o
