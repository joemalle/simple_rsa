#include "util.h"

#include <fstream>

namespace alice {
	// These two numbers must be primes
	const number_t p = 49667;
	const number_t q = 50723;
}

int main(int argc, char * * argv) {
	std::ofstream pub("alice.public.h", std::ios::out);
	std::ofstream pri("alice.private.h", std::ios::out);
	
	number_t n = alice::p * alice::q;
	number_t phi_n = (alice::p - 1) * (alice::q - 1);
	number_t b;
	number_t b_inv;
	
	set_b_and_b_inv(b, b_inv, phi_n);
	
	pub << "namespace alice {" << std::endl;
	pub << "\tconst number_t n = " << n << ";" << std::endl;
	pub << "\tconst number_t b = " << b << ";" << std::endl;
	pub << "}" << std::endl;
	
	pri << "namespace alice {" << std::endl;
	pri << "\tconst number_t p = " << alice::p << ";" << std::endl;
	pri << "\tconst number_t q = " << alice::q << ";" << std::endl;
	pri << "\tconst number_t b_inv = " << b_inv << ";" << std::endl;
	pri << "}" << std::endl;
}
