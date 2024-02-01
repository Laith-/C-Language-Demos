#include "checkinput.h"
#include <stdio.h>
#include <stdlib.h>

void checkInput(int err) {
  if (!err || err == EOF) {
    printf("\nInvalid input!\n");
    exit(1);
  }
}
