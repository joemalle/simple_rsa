#pragma once

#ifdef BIG_INT

#include <gmpxx.h>

#define integer_t mpz_class

// can be 1 for most significant word first
// or -1 for least significant first
const int ENDIANNESS = 1;

#else

#define integer_t int

#endif
