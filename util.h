#pragma once

#include <cstdlib>
#include <ctime>

typedef long long number_t;

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
number_t modpow(number_t base, number_t exp, const number_t modulus) {
  base %= modulus;
  number_t result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

/*
 * returns 1 if b_inv has been set to the inverse of b mod a
 *
 * This is Algorithm 5.3: Multiplicative Inverse(a, b) in
 * Cryptography: Theory and Practice, Third Edition By Douglas R. Stinson
 */
number_t mult_inv(const number_t a, const number_t  b, number_t & b_inv) {
	number_t a_0 = a;
	number_t b_0 = b;
	number_t t_0 = 0;
	number_t t = 1;
	number_t q = a_0 / b_0;
	number_t r = a_0 - q * b_0;
	
	while (r > 0) {
		number_t temp = (t_0 - q * t) % a;
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
void set_b_and_b_inv(number_t & b, number_t & b_inv, const number_t phi_n) {
	srand (time(NULL));
	while (true) {
		b = 1 + (rand() % (phi_n - 1));
		
		if (1 == mult_inv(phi_n, b, b_inv)) {
			break;
		}
	}
	
	if (b_inv < 0) b_inv += phi_n;
}
