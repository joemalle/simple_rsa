#include <cstdio>

#include "alice.public.h"
#include "alice.private.h"
#include "big_int.h"
#include "big_util.h"

// Alice receives the message and decodes it



int main() {
	mpz_class big;
	
	gmp_scanf ("%Zd", &big);
	
	modpow(big, alice::b_inv, alice::n);
	
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

