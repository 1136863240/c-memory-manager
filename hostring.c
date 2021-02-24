#include "hostring.h"

void string_print(struct String s) {
    printf("%s\n", s.str);
}

struct String string_create(struct Memory* m) {
    struct String str;
    struct MemoryReturn ret = memory_create(m, sizeof(char));
    str.mem_id = ret.id;
    str.str = (char*)ret.m;
    str.str[0] = '\0';
    str.length = 0;
    return str;
}

struct String char2string(struct Memory* m, char c) {
    struct String s;
    struct MemoryReturn ret = memory_create(m, sizeof(char) * 2);
    s.mem_id = ret.id;
    s.str = (char*)ret.m;
    s.str[0] = c;
    s.str[1] = '\0';
    s.length = 1;
    return s;
}

struct String chars2string(struct Memory* m, char* str) {
    char* _str = str;
    int _str_len = 0;
    while (_str != NULL && *_str) {
        ++_str_len;
        ++_str;
    }
    struct String s;
    struct MemoryReturn ret = memory_create(m, sizeof(char) * (_str_len + 1));
    s.mem_id = ret.id;
    s.str = (char*)ret.m;
    char* _str2 = str;
    int i = 0;
    for (; i < _str_len; ++i) {
        s.str[i] = _str2[i];
    }
    s.str[i] = '\0';
    s.length = _str_len;
    return s;
}

struct String string_append_chars(struct Memory* m, struct String str1, char* str2) {
    struct String _str2 = chars2string(m, str2);
    struct String _ret = string_append(m, str1, _str2);
    memory_free(m, _str2.mem_id);
    return _ret;
}

struct String string_append(struct Memory* m, struct String str1, struct String str2) {
    int i = str1.length;
    int j = 0;
    str1.length += str2.length;
    struct MemoryReturn ret = memory_realloc(m, str1.mem_id, sizeof(char) * (str1.length + 1));
    str1.str = (char*)ret.m;
    for (; i < str1.length; ++i) {
        str1.str[i] = str2.str[j];
        ++j;
    }
    str1.str[i] = '\0';
    return str1;
}

struct String string_prepend_chars(struct Memory* m, struct String str1, char* str2) {
    struct String _str2 = chars2string(m, str2);
    struct String _ret = string_prepend(m, str1, _str2);
    memory_free(m, _str2.mem_id);
    return _ret;
}

struct String string_prepend(struct Memory* m, struct String str1, struct String str2) {
    int i = 0;
    int j = 0;
    int _s_len = str1.length + str2.length;
    struct String _s = string_create(m);
    _s.length = _s_len;
    struct MemoryReturn ret = memory_create(m, sizeof(char) * (_s_len + 1));
    _s.mem_id = ret.id;
    _s.str = (char*)ret.m;
    for (; i < str2.length; ++i) {
        _s.str[i] = str2.str[i];
    }
    for (; i < _s_len; ++i) {
        _s.str[i] = str1.str[j];
        ++j;
    }
    _s.str[i] = '\0';
    return _s;
}

struct String string_reset(struct Memory* m, struct String str) {
    str = string_create(m);
    return str;
}

bool string_equal_char(struct String str1, char c) {
    if (str1.length != 1) {
        return false;
    }
    if (str1.str[0] != c) {
        return false;
    }
    return true;
}

bool string_equal_string(struct String str1, struct String str2) {
    if (str1.length != str2.length) {
        return false;
    }
    int len = str1.length;
    for (int i = 0; i < len; ++i) {
        if (str1.str[i] != str2.str[i]) {
            return false;
        }
    }
    return true;
}

char string_get_last(struct String str) {
    if (str.length <= 0) {
        return (char)0;
    }
    return str.str[str.length - 1];
}
