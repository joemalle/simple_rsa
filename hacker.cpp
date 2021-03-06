#include "util.h"
#include "alice.public.h"


#include <iostream>

// Haxor tries to decode Bob's message by factoring n

int main() {
	int p = 2;
	int q;
	
	// this is O(n^(1/2)) since p must be <= n^1/2
	while (alice::n % p != 0) {
		++p;
	}
	
	q = alice::n / p;
	
	int phi_n = (p - 1) * (q - 1);
	
	int b_inv;
	
	int t = mult_inv(phi_n, alice::b, b_inv);
	
	if (t != 1) {
		std::cout << "Error: couldn't factor n" << std::endl;
		return 1;
	}
	
	if (b_inv < 0) b_inv += phi_n;
	
	int i;
	while (std::cin >> i) {
		std::cout << (char) modpow(i, b_inv, alice::n);
	}
}
