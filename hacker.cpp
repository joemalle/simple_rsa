#include "util.h"
#include "alice.public.h"


#include <iostream>

// Haxor tries to decode Bob's message by factoring n

int main() {
	number_t p = 2;
	number_t q;
	
	// this is O(n^(1/2)) since p must be <= n^1/2
	while (alice::n % p != 0) {
		++p;
	}
	
	q = alice::n / p;
	
	number_t phi_n = (p - 1) * (q - 1);
	
	number_t b_inv;
	
	number_t t = mult_inv(phi_n, alice::b, b_inv);
	
	if (t != 1) {
		std::cout << "Error: couldn't factor n" << std::endl;
		return 1;
	}
	
	if (b_inv < 0) b_inv += phi_n;
	
	number_t i;
	while (std::cin >> i) {
		std::cout << (char) modpow(i, b_inv, alice::n);
	}
}
