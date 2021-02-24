#ifndef HOFILE_H
#define HOFILE_H

#include <stdio.h>
#include "homemory.h"
#include "hostring.h"

struct String read_line(struct Memory* mem, FILE* file);
struct String read_all(struct Memory* mem, FILE* file);

#endif // !HOFILE_H
