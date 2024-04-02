#ifndef __VTEST_H__

#define __VTEST_H__

#include <memory.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST(name) void test_##name(void)

static int tests_failed = 0;

#define vassert(cond)                                                          \
    do {                                                                       \
        if (!(cond)) {                                                         \
            fprintf(stderr, "%s:%d ", __FILE__, __LINE__);                     \
            fprintf(stderr, "assertion %s failed\n", #cond);                   \
            tests_failed = 1;                                                  \
        }                                                                      \
    } while (0)

#define vassert_int_eq(a, b)                                                   \
    do {                                                                       \
        if ((a) != (b)) {                                                      \
            fprintf(stderr, "%s:%d ", __FILE__, __LINE__);                     \
            fprintf(stderr, "assertion failed: %s != %s, ", #a, #b);           \
            fprintf(stderr, "%s = %d, %s = %d\n", #a, (a), #b, (b));           \
            tests_failed = 1;                                                  \
        }                                                                      \
    } while (0)

#define vassert_uint_eq(a, b)                                                  \
    do {                                                                       \
        if ((a) != (b)) {                                                      \
            fprintf(stderr, "%s:%d ", __FILE__, __LINE__);                     \
            fprintf(stderr, "assertion failed: %s != %s, ", #a, #b);           \
            fprintf(stderr, "%s = %u, %s = %u\n", #a, (a), #b, (b));           \
            tests_failed = 1;                                                  \
        }                                                                      \
    } while (0)

#define vassert_mem_eq(a, b, size)                                             \
    do {                                                                       \
        if (memcmp((a), (b), (size)) != 0) {                                   \
            fprintf(stderr, "%s:%d ", __FILE__, __LINE__);                     \
            fprintf(stderr, "assertion failed: %s != %s\n", #a, #b);           \
            tests_failed = 1;                                                  \
        }                                                                      \
    } while (0)

#define vassert_str_eq(a, b)                                                   \
    do {                                                                       \
        size_t a_len = strlen((a));                                            \
        size_t b_len = strlen((b));                                            \
        if (a_len != b_len) {                                                  \
            fprintf(stderr, "%s:%d ", __FILE__, __LINE__);                     \
            fprintf(stderr, "assertion failed: %s != %s, ", #a, #b);           \
            fprintf(stderr, "%s = %s, %s = %s\n", #a, (a), #b, (b));           \
            tests_failed = 1;                                                  \
        }                                                                      \
        if (strcmp((a), (b)) != 0) {                                           \
            fprintf(stderr, "%s:%d ", __FILE__, __LINE__);                     \
            fprintf(stderr, "assertion failed: %s != %s, ", #a, #b);           \
            fprintf(stderr, "%s = %s, %s = %s\n", #a, (a), #b, (b));           \
            tests_failed = 1;                                                  \
        }                                                                      \
    } while (0)

#define run_test(name)                                                         \
    do {                                                                       \
        test_##name();                                                         \
    } while (0)

#define tests_done()                                                           \
    do {                                                                       \
        if (tests_failed) {                                                    \
            fprintf(stderr, "tests failed\n");                                 \
            exit(1);                                                           \
        }                                                                      \
        printf("all tests passed\n");                                          \
        exit(0);                                                               \
    } while (0)

#endif /* __VTEST_H__ */
