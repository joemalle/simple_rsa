all:
	
	g++ -std=c++11 public_maker.cpp -o pm
	./pm > alice.public.h
	g++ -std=c++11 alice.cpp -o alice
	g++ -std=c++11 bob.cpp -o bob
	g++ -std=c++11 hacker.cpp -o hacker

run:
	echo "Super secret message" | ./bob > bob.out
	./alice < bob.out > alice.out
	./hacker < bob.out > hacker.out

clean:
	rm -f alice bob hacker *.out pm
