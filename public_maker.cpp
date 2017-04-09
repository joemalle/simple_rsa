#include "util.h"

#include <fstream>

namespace alice {
	// These two numbers must be primes
	const int p = 101;
	const int q = 113;
}

int main(int argc, char * * argv) {
	std::ofstream pub("alice.public.h", std::ios::out);
	std::ofstream pri("alice.private.h", std::ios::out);
	
	int n = alice::p * alice::q;
	int phi_n = (alice::p - 1) * (alice::q - 1);
	int b;
	int b_inv;
	
	set_b_and_b_inv(b, b_inv, phi_n);
	
	pub << "namespace alice {" << std::endl;
	pub << "\tconst int n = " << n << ";" << std::endl;
	pub << "\tconst int b = " << b << ";" << std::endl;
	pub << "}" << std::endl;
	
	pri << "namespace alice {" << std::endl;
	pri << "\tconst int p = " << alice::p << ";" << std::endl;
	pri << "\tconst int q = " << alice::q << ";" << std::endl;
	pri << "\tconst int b_inv = " << b_inv << ";" << std::endl;
	pri << "}" << std::endl;
}
