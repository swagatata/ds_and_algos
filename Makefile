test: main
	g++ kruskal_tests.cpp -o kruskal_tests
	./kruskal_tests	input

main: kruskal.cpp
	g++ kruskal.cpp -o kruskal
