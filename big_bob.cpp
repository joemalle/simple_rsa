#include <cstdio>

#include "alice.public.h"
#include "big_int.h"
#include "big_util.h"

// Bob encodes the message for Alice's eyes only

int main() {
	mpz_class big;
	char i;
	
	while ((i = getc(stdin)) != EOF) {
		big <<= 8;
		big += (int) i;
	}
	
	modpow(big, alice::b, alice::n);
	
	gmp_printf ("%Zd", big.get_mpz_t());
}
