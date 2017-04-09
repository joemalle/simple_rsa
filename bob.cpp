#include "util.h"
#include "alice.public.h"

#include <iostream>

// Bob encodes the message for Alice's eyes only

int main() {
	char i;
	while (std::cin.get(i)) {
		std::cout << modpow(i, alice::b, alice::n) << " ";
	}
}
