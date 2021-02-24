#ifndef HOSTRING_H
#define HOSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "homemory.h"

struct String {
    int mem_id;
    int length;
    char* str;
};

void string_print(struct String s);
struct String string_create(struct Memory* m);
struct String char2string(struct Memory* m, char str);
struct String chars2string(struct Memory* m, char* str);
struct String string_append_chars(struct Memory* m, struct String str1, char* str2);
struct String string_append(struct Memory* m, struct String str1, struct String str2);
struct String string_prepend_chars(struct Memory* m, struct String str1, char* str2);
struct String string_prepend(struct Memory* m, struct String str1, struct String str2);
struct String string_reset(struct Memory* m, struct String str);
bool string_equal_char(struct String str1, char c);
bool string_equal_string(struct String str1, struct String str2);
char string_get_last(struct String str);

#endif
