#ifndef utils_h
#define utils_h

#include <stdlib.h>
#include <stdio.h>

#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
#define RESET "\x1B[0m"

static void allocation_failed() {
  printf(RED "Out of Memory\n" RESET);
  exit(0);
}

#endif
