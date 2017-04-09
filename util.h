#pragma once

#include <cstdlib>
#include <ctime>


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
int modpow(int base, int exp, const int modulus) {
  base %= modulus;
  int result = 1;
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
int mult_inv(const int a, const int  b, int & b_inv) {
	int a_0 = a;
	int b_0 = b;
	int t_0 = 0;
	int t = 1;
	int q = a_0 / b_0;
	int r = a_0 - q * b_0;
	
	while (r > 0) {
		int temp = (t_0 - q * t) % a;
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
void set_b_and_b_inv(int & b, int & b_inv, const int phi_n) {
	srand (time(NULL));
	while (true) {
		b = 1 + (rand() % (phi_n - 1));
		
		if (1 == mult_inv(phi_n, b, b_inv)) {
			break;
		}
	}
	
	if (b_inv < 0) b_inv += phi_n;
}
