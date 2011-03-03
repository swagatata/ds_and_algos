CXXFLAGS=-D DEBUG

test: kruskal_tests

kruskal_tests: kruskal_tests.cpp kruskal.h
	g++ $(CXXFLAGS) kruskal_tests.cpp -o kruskal_tests
	./kruskal_tests	test_data/kruskal_tests_input.txt

kruskal: kruskal.cpp kruskal.h
	g++ $(CXXFLAGS) kruskal.cpp -o kruskal
