CXXFLAGS=
# Uncomment the following line to enable DEBUG mode
# CXXFLAGS+=-D DEBUG -g -Wall

# These targets don't generate executables
.PHONY: test clean

# Default Build target
test: kruskal_tests permut_tests
	rm -rf kruskal_tests

kruskal_tests: kruskal_tests.cpp kruskal.h test_data/kruskal_tests_input.txt
	g++ $(CXXFLAGS) kruskal_tests.cpp -o kruskal_tests
	./kruskal_tests	test_data/kruskal_tests_input.txt

permutations_without_duplicates: permutations_without_duplicates.cpp
	g++ $(CXXFLAGS) $< -o $@

permutations_without_duplicates_v2: permutations_without_duplicates_v2.cpp
	g++ $(CXXFLAGS) $< -o $@	

kruskal: kruskal.cpp kruskal.h
	g++ $(CXXFLAGS) kruskal.cpp -o kruskal

permut_tests: permutations_without_duplicates permutations_without_duplicates_v2
	./permutations_without_duplicates abc | grep 'Count: 6'
	./permutations_without_duplicates abcdef | grep 'Count: 720'
	./permutations_without_duplicates aaabb | grep 'Count: 10'
	./permutations_without_duplicates aabbcc | grep 'Count: 90'
	./permutations_without_duplicates_v2 abc | grep 'Count: 6'
	./permutations_without_duplicates_v2 abcdef | grep 'Count: 720'
	./permutations_without_duplicates_v2 aaabb | grep 'Count: 10'
	./permutations_without_duplicates_v2 aabbcc | grep 'Count: 90'
	@echo "All tests pass..."

clean:
	rm -rf kruskal kruskal_tests permutations_without_duplicates permutations_without_duplicates_v2
