#include <stdio.h>
#include "utils.h"

int main(int argc, char **argv) {
    int i = strmaxlen(argv, argc);
    printf("max len: %i\n", i);

    int j = strminlen(argv, argc);
    printf("min len: %i\n", j);

    return 0;
}
