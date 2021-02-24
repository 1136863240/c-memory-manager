#include <stdio.h>
#include "../../hostring.h"

int main() {
    struct Memory* memory = memory_init();
    struct String str = string_create(memory);
    struct String str2 = string_create(memory);
    str2 = char2string(memory, 'a');
    str = string_append(memory, str, str2);
    struct String str3 = str;
    str3 = char2string(memory, 'b');
    printf("%d %s\n", str.length, str.str);
    printf("%d %s\n", str2.length, str2.str);
    printf("%d %s\n", str3.length, str3.str);
    memory_free_all(memory);

    return 0;
}
