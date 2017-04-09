#include "util.h"
#include "alice.public.h"
#include "alice.private.h"

#include <iostream>

// Alice receives the message and decodes it

int main() {
	int i;
	while (std::cin >> i) {
		std::cout << (char) modpow(i, alice::b_inv, alice::n);
	}
}
