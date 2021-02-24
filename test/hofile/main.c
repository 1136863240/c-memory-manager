#include <stdio.h>
#include "../../hofile.h"

int main() {
    struct Memory* mem = memory_init();
    FILE* file = fopen("a.txt", "r");
    struct String str = read_all(mem, file);
    string_print(str);
    memory_free_all(mem);

    return 0;
}
