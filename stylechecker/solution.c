#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>

const int MAX_LEN = 80;
const char *badspaces[5] = {"if(", "for(", "while(", "){", "}("};
const int BADSPACES_LEN = 5;
const char *types[4] = {"int", "char", "bool", "struct"};
const int TYPES_LEN = 4;

// char_limit(str): Returns true if str is <= the character limit MAX_LEN
// requires: str is a valid string
bool char_limit(const char *str) {
    assert(str);
    return strlen(str) <= MAX_LEN;
}

// starts_with(a, b): Returns true if a starts with b
// examples: "bod" starts with "bo", but "bo" does not start with "bod"
// requires: str a, b are valid strings
bool starts_with(const char *a, const char *b) {
    assert(a);
    assert(b);
    int len_a = strlen(a);
    int len_b = strlen(b);
    if (len_b > len_a) {
        return false;
    }
    for (int i = 0; i < len_b; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

// space_check(str): Returns false if there's an instance of any bad spacing errors denoted in badspaces
//   The space checker ignores any bad spaces after a single-line comment "//"
// requires: str is a valid string
bool space_check(const char *str) {
    assert(str);
    int len = strlen(str);
    for (int i = 0; i < len; ++i) {
        if (starts_with(str, "//")) {
            return true;
        }
        for (int j = 0; j < BADSPACES_LEN; ++j) {
            const char *badspace = badspaces[j];
            if (starts_with(str, badspace)) {
                return false;
            }
        }
        ++str;
    }
    return true;
}

// initialized(str): Returns false if str meets this criteria:
//  1) After any initial whitespace, it starts with one of the types given by the types array
//  2) Ends with ;
//  3) Does not contain = 
// examples: "     int a;" -> false
//           "     int a; " -> true
//           "int** a;" -> false
//           "int a = 5;" -> true
// requires: str is a valid string
bool initialized(const char *str) {
    assert(str);
    int len = strlen(str);

    // Checks for ;
    if (len == 0 || str[len - 1] != ';') {
        return true;
    }

    // Checks for =
    for (int i = 0; i < len; ++i) {
        if (str[i] == '=') {
            return true;
        }
    }

    // Gets rid of initial whitespace
    for (int i = 0; i < len; ++i) {
        if (str[0] == ' ') {
            str++;
        } else {
            break;
        }
    }
    
    // Detects if it starts with anything in types
    for (int i = 0; i < TYPES_LEN; ++i) {
        if (starts_with(str, types[i])) {
            return false;
        }
    }
    return true;
}


int main(void) {
    // Testing harness you don't have to worry about
    char str[1000];
    int line = 1;
    while (fgets(str, sizeof(str), stdin) != NULL) {
        int len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0'; // Remove newline
        }
        if (!char_limit(str)) {
            printf("Exceeded character limit on line %d\n", line);
        }
        if (!space_check(str)) {
            printf("Missing whitespace on line %d\n", line);
        }
        if (!initialized(str)) {
            printf("Uninitialized variable on line %d\n", line);
        }
        ++line;
    }
    return 0;
}
