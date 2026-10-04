#ifndef INOUT_H
#define INOUT_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void InOut_out(const char *fmt, ...) {
    if (!fmt) return;
    va_list a; va_start(a, fmt);
    vfprintf(stdout, fmt, a);
    va_end(a); fflush(stdout);
}

static inline int InOut_in(const char *prompt, char *buf, size_t size) {
    if (!buf || !size) return -1;
    if (prompt) InOut_out("%s", prompt);
    if (!fgets(buf, (int)size, stdin)) { buf[0] = 0; return -1; }
    size_t n = strlen(buf);
    if (n && buf[n-1] == '\n') buf[--n] = 0;
    return (int)n;
}

#ifdef __cplusplus
}
#endif

#define out(...) InOut_out(__VA_ARGS__)
#define in(...)  InOut_in(__VA_ARGS__)

#endif