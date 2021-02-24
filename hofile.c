#include "hofile.h"
#include <stdlib.h>

struct String read_line(struct Memory* mem, FILE* file) {
    struct String str = string_create(mem);
    char* c = (char*)malloc(sizeof(char) * 2);
    fread(c, 1, 1, file);
    c[1] = '\0';
    while (feof(file) == 0) {
        if (c[0] == '\n') {
            break;
        }
        str = string_append_chars(mem, str, c);
        fread(c, 1, 1, file);
        c[1] = '\0';
    }
    free(c);
    return str;
}

struct String read_all(struct Memory* mem, FILE* file) {
    struct String str = string_create(mem);
    char* c = (char*)malloc(sizeof(char) * 2);
    c[1] = '\0';
    fread(c, 1, 1, file);
    while (feof(file) == 0) {
        str = string_append_chars(mem, str, c);
        fread(c, 1, 1, file);
        c[1] = '\0';
    }
    free(c);
    return str;
}
