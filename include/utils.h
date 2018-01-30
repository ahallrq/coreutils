#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>

int strmaxlen(char **str_list, int len) {
    int max_len = 0;

    for (int pos = 0; pos < len; pos++) {
        int l = strlen(str_list[pos]);
        if (l > max_len) {
            max_len = l;
        }
    }

    return max_len;
}

int strminlen(char **str_list, int len) {
    int min_len = -1;

    for (int pos = 0; pos < len; pos++) {
        int l = strlen(str_list[pos]);
        if (l < min_len || min_len == -1) {
            min_len = l;
        }
    }

    return min_len;
}

#endif
