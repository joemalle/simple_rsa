#include <cstdio>

#include "alice.public.h"
#include "big_int.h"
#include "big_util.h"

// Haxor tries to decode Bob's message by factoring n

int main() {
	integer_t p = 2;
	integer_t q;
	
	// this is O(n^(1/2)) since p must be <= n^1/2
	while (alice::n % p != 0) {
		++p;
	}
	
	q = alice::n / p;
	
	integer_t phi_n = (p - 1) * (q - 1);
	
	integer_t b_inv;
	
	integer_t t = mult_inv(phi_n, alice::b, b_inv);
	
	if (t != 1) {
		printf("Error: couldn't factor n\n");
		return 1;
	}
	
	if (b_inv < 0) b_inv += phi_n;
	
	// rest is copied from alice
	
	mpz_class big;
	
	gmp_scanf ("%Zd", &big);
	
	modpow(big, b_inv, alice::n);
	
	// the rest is just to output the message
	
	char buf[1000] = {0};
	size_t idx = 0;
	char i;
	
	while (big > 0) {
		mpz_class x = big % mpz_class(256);
		i = (char)x.get_ui();
		big >>= 8;
		buf[idx++] = i;
		if (idx == 999) {
			break;
		}
	}
	
	reverse(buf);
	
	printf("%s", buf);
}

