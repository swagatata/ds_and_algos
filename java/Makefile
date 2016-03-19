all: classes jar test

classes: dirs
	javac -sourcepath Algorithms/src -d build/classes/ `find . -iname '*.java'`

jar: manifest.txt classes
	jar cfm build/ds-and-algos.jar manifest.txt -C build/classes .

dirs:
	mkdir -p build/classes

testdata: dirs
	cp -r Algorithms/input build/

test: jar dirs testdata
	cd build/ && java -jar ds-and-algos.jar

clean:
	$(RM) -r build

.PHONY: clean test testdata dirs jar classes
