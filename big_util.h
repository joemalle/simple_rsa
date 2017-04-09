#pragma once

#include <cstdlib>
#include <ctime>

#include "big_int.h"

/*
 * returns (base ^ exp) % modulus
 *
 * This function should avoid overflow
 * Time complexity: O(log(e))
 *
 * I found this on
 * http://stackoverflow.com/questions/8496182/calculating-powa-b-mod-n
 * ... who found it on page 244 of
 * Schneier, Bruce (1996). Applied Cryptography: Protocols, Algorithms, and Source Code in C, Second Edition (2nd ed.). Wiley. ISBN 978-0-471-11709-4.
 */


#include <cstdio>
#include <gmp.h>

mpz_class modpow(mpz_class base, mpz_class exp, const mpz_class modulus) {
  base %= modulus;
  mpz_class result = 1;
  while (exp > 0) {
    if (mpz_odd_p(exp.get_mpz_t())) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

void reverse(char s[]) {
    int length = strlen(s) ;
    int c, i, j;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/*
 * returns 1 if b_inv has been set to the inverse of b mod a
 *
 * This is Algorithm 5.3: Multiplicative Inverse(a, b) in
 * Cryptography: Theory and Practice, Third Edition By Douglas R. Stinson
 */
integer_t mult_inv(const integer_t a, const integer_t  b, integer_t & b_inv) {
	integer_t a_0 = a;
	integer_t b_0 = b;
	integer_t t_0 = 0;
	integer_t t = 1;
	integer_t q = a_0 / b_0;
	integer_t r = a_0 - q * b_0;
	
	while (r > 0) {
		integer_t temp = (t_0 - q * t) % a;
		t_0 = t;
		t = temp;
		a_0 = b_0;
		b_0 = r;
		q = a_0 / b_0;
		r = a_0 - q * b_0;
	}
	
	b_inv = t;
	return b_0;
}

/*
 * This is a driver that calls mult_inv until it finds a suitable b
 *
 * obviously it modifies b and b_inv...
 */
void set_b_and_b_inv(integer_t & b, integer_t & b_inv, const integer_t phi_n) {
	srand (time(NULL));
	while (true) {
		b = 1 + (rand() % (phi_n - 1));
		
		if (1 == mult_inv(phi_n, b, b_inv)) {
			break;
		}
	}
	
	if (b_inv < 0) b_inv += phi_n;
}
