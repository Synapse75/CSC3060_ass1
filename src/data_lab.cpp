#include "data_lab.hpp"
#include <cstdint>

namespace data_lab {

int32_t add(int32_t a, int32_t b) {
    uint32_t a_unsigned = static_cast<uint32_t>(a);
    uint32_t b_unsigned = static_cast<uint32_t>(b);
    uint32_t c0 = a_unsigned ^ b_unsigned;
    uint32_t d0 = (a_unsigned & b_unsigned) << 1;
    uint32_t c1 = c0 ^ d0;
    uint32_t d1 = (c0 & d0) << 1;
    uint32_t c2 = c1 ^ d1;
    uint32_t d2 = (c1 & d1) << 1;
    uint32_t c3 = c2 ^ d2;
    uint32_t d3 = (c2 & d2) << 1;
    uint32_t c4 = c3 ^ d3;
    uint32_t d4 = (c3 & d3) << 1;
    uint32_t c5 = c4 ^ d4;
    uint32_t d5 = (c4 & d4) << 1;
    uint32_t c6 = c5 ^ d5;
    uint32_t d6 = (c5 & d5) << 1;
    uint32_t c7 = c6 ^ d6;
    uint32_t d7 = (c6 & d6) << 1;
    uint32_t c8 = c7 ^ d7;
    uint32_t d8 = (c7 & d7) << 1;
    uint32_t c9 = c8 ^ d8;
    uint32_t d9 = (c8 & d8) << 1;
    uint32_t c10 = c9 ^ d9;
    uint32_t d10 = (c9 & d9) << 1;
    uint32_t c11 = c10 ^ d10;
    uint32_t d11 = (c10 & d10) << 1;
    uint32_t c12 = c11 ^ d11;
    uint32_t d12 = (c11 & d11) << 1;
    uint32_t c13 = c12 ^ d12;
    uint32_t d13 = (c12 & d12) << 1;
    uint32_t c14 = c13 ^ d13;
    uint32_t d14 = (c13 & d13) << 1;
    uint32_t c15 = c14 ^ d14;
    uint32_t d15 = (c14 & d14) << 1;
    uint32_t c16 = c15 ^ d15;
    uint32_t d16 = (c15 & d15) << 1;
    uint32_t c17 = c16 ^ d16;
    uint32_t d17 = (c16 & d16) << 1;
    uint32_t c18 = c17 ^ d17;
    uint32_t d18 = (c17 & d17) << 1;
    uint32_t c19 = c18 ^ d18;
    uint32_t d19 = (c18 & d18) << 1;
    uint32_t c20 = c19 ^ d19;
    uint32_t d20 = (c19 & d19) << 1;
    uint32_t c21 = c20 ^ d20;
    uint32_t d21 = (c20 & d20) << 1;
    uint32_t c22 = c21 ^ d21;
    uint32_t d22 = (c21 & d21) << 1;
    uint32_t c23 = c22 ^ d22;
    uint32_t d23 = (c22 & d22) << 1;
    uint32_t c24 = c23 ^ d23;
    uint32_t d24 = (c23 & d23) << 1;
    uint32_t c25 = c24 ^ d24;
    uint32_t d25 = (c24 & d24) << 1;
    uint32_t c26 = c25 ^ d25;
    uint32_t d26 = (c25 & d25) << 1;
    uint32_t c27 = c26 ^ d26;
    uint32_t d27 = (c26 & d26) << 1;
    uint32_t c28 = c27 ^ d27;
    uint32_t d28 = (c27 & d27) << 1;
    uint32_t c29 = c28 ^ d28;
    uint32_t d29 = (c28 & d28) << 1;
    uint32_t c30 = c29 ^ d29;
    uint32_t d30 = (c29 & d29) << 1;
    uint32_t c31 = c30 ^ d30;
    uint32_t d31 = (c30 & d30) << 1;
    return static_cast<int32_t>(c31);
}

int32_t subtract(int32_t a, int32_t b) {
    return add(a, add(~b, 1u));
}

int32_t multiply(int32_t a, int32_t b) {
    uint32_t a_unsigned = static_cast<uint32_t>(a);
    uint32_t b_unsigned = static_cast<uint32_t>(b);
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
        if (b_unsigned & (1u << i)) {
            result = add(result, a_unsigned << i);
        }
    }
    return static_cast<int32_t>(result);
}

int32_t divide(int32_t a, int32_t b) {
    uint32_t a_unsigned = static_cast<uint32_t>(a);
    uint32_t b_unsigned = static_cast<uint32_t>(b);
    bool is_negative = (a_unsigned >> 31) ^ (b_unsigned >> 31); // Determine the sign of the result
    if (a_unsigned >> 31) {
        a_unsigned = add(~a_unsigned, 1); // Make a positive
    }
    if (b_unsigned >> 31) {
        b_unsigned = add(~b_unsigned, 1); // Make b positive
    }
    uint32_t quotient = 0;
    for (int i = 31; i >= 0; --i) {
        if (!(b_unsigned >> (31 - i))) {
            uint32_t b_modified = b_unsigned << i;
            uint32_t diff = subtract(a_unsigned, b_modified);
            if (!(diff >> 31)) {
                a_unsigned = diff;
                quotient |= (1u << i);
            }
        }
    }
    int32_t result = static_cast<int32_t>(quotient);
    if (is_negative) {
        return add(~result, 1);
    } else {
        return result;
    }
}

int32_t modulo(int32_t a, int32_t b) {
    uint32_t a_unsigned = static_cast<uint32_t>(a);
    uint32_t b_unsigned = static_cast<uint32_t>(b);
    bool is_negative = (a_unsigned >> 31); // Determine the sign of the result
    if (a_unsigned >> 31) {
        a_unsigned = add(~a_unsigned, 1); // Make a positive
    }
    if (b_unsigned >> 31) {
        b_unsigned = add(~b_unsigned, 1); // Make b positive
    }
    uint32_t quotient = 0;
    for (int i = 31; i >= 0; --i) {
        if (!(b_unsigned >> (31 - i))) {
            uint32_t b_modified = b_unsigned << i;
            uint32_t diff = subtract(a_unsigned, b_modified);
            if (!(diff >> 31)) {
                a_unsigned = diff;
                quotient |= (1u << i);
            }
        }
    }
    int32_t result = static_cast<int32_t>(a_unsigned);
    if (is_negative) {
        return add(~result, 1);
    } else {
        return result;
    }
}

}  // namespace data_lab