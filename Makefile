test: main
	g++ kruskal_tests.cpp -o kruskal_tests
	./kurskal_tests	

main: kruskal.cpp
	g++ kruskal.cpp -o kruskal
	./kruskal input
