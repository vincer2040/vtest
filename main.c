#include <stdio.h>
#include <stdint.h>
#include "vtest.h"

int add(int a, int b) {
    return a + b;
}

uint32_t addu(uint32_t a, uint32_t b) {
    return a + b;
}

TEST(add_numbers) {
    vassert_uint_eq(add(1, 1), 3);
}

TEST(add_numbers_u) {
    vassert_uint_eq(addu(1, 1), 3);
}

TEST(mem) {
    vassert_mem_eq("abc", "ab", 3);
}

TEST(strings) {
    vassert_str_eq("abc", "cba");
}

int main(void) {
    run_test(add_numbers);
    run_test(add_numbers_u);
    run_test(mem);
    run_test(strings);
    tests_done();
    return 0;
}
