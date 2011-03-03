CXXFLAGS=
# Uncomment the following line to enable DEBUG mode
# CXXFLAGS+=-D DEBUG -g -Wall

# These targets don't generate executables
.PHONY: test clean

# Default Build target
test: kruskal_tests
	rm -rf kruskal_tests

kruskal_tests: kruskal_tests.cpp kruskal.h test_data/kruskal_tests_input.txt
	g++ $(CXXFLAGS) kruskal_tests.cpp -o kruskal_tests
	./kruskal_tests	test_data/kruskal_tests_input.txt

kruskal: kruskal.cpp kruskal.h
	g++ $(CXXFLAGS) kruskal.cpp -o kruskal

clean:
	rm -rf kruskal kruskal_tests
