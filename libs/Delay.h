#ifndef DELAY_H
#define DELAY_H

#include <time.h>
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline void delay_ms(long ms) {
    if (ms <= 0) return;
    struct timespec ts;
    ts.tv_sec  = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);
}
static inline void delay_s(long s)   { if (s > 0) { struct timespec ts = { s, 0 }; nanosleep(&ts, NULL); } }
static inline void delay_min(long m) { delay_s(m * 60); }
static inline void delay_h(long h)   { delay_s(h * 3600); }

typedef void (*DelayFn)(void *arg);

static inline void delay_run(DelayFn fn, void *arg) {
    pthread_t t;
    if (pthread_create(&t, NULL, (void *(*)(void *))fn, arg) == 0) {
        pthread_detach(t);
    }
}

#ifdef __cplusplus
}
#endif
#endif