CXX=g++
CXXFLAGS=-std=c++11
LFLAGS=-lgmpxx -lgmp

all:	
	$(CXX) $(CXXFLAGS) public_maker.cpp -o pm $(LFLAGS)
	./pm
	$(CXX) $(CXXFLAGS) alice.cpp -o alice $(LFLAGS)
	$(CXX) $(CXXFLAGS) bob.cpp -o bob $(LFLAGS)
	$(CXX) $(CXXFLAGS) hacker.cpp -o hacker $(LFLAGS)

big_int:
	$(CXX) $(CXXFLAGS) -DBIG_INT big_public_maker.cpp -o pm $(LFLAGS)
	./pm
	$(CXX) $(CXXFLAGS) -DBIG_INT big_alice.cpp -o alice $(LFLAGS)
	$(CXX) $(CXXFLAGS) -DBIG_INT big_bob.cpp -o bob $(LFLAGS)
	$(CXX) $(CXXFLAGS) -DBIG_INT big_hacker.cpp -o hacker $(LFLAGS)

run:
	echo "Super secret message" | ./bob > bob.out
	./alice < bob.out > alice.out
	./hacker < bob.out > hacker.out

clean:
	rm -f alice bob hacker *.out pm alice.*.h
