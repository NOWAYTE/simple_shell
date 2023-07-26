#include "shell.h"
#include <string.h>

int _strcmp(const char* s1, const char* s2) {
    int i;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return s1[i] - s2[i];
}

char* _strcat(char* destination, const char* source) {
    char* ptr = destination + strlen(destination);
    while (*source != '\0') {
        *ptr++ = *source++;
    }
    *ptr = '\0';
    return destination;
}

size_t _strspn(const char* s, const char* accept) {
    size_t count = 0;
    while (*s != '\0' && strchr(accept, *s) != NULL) {
        count++;
        s++;
    }
    return count;
}

char* _strchr(const char* s, int c) {
    while (*s != '\0') {
        if (*s == c) {
            return (char*)s;
        }
        s++;
    }
    if (c == '\0') {
        return (char*)s;
    }
    return NULL;
}

size_t _strcspn(const char* s, const char* reject) {
    size_t count = 0;
    while (*s != '\0' && strchr(reject, *s) == NULL) {
        count++;
        s++;
    }
    return count;
}
