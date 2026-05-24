CXX     = g++
ARGS    = -Wall -std=c++17

OUT     = run

build: main.o set.o autotest.o
	$(CXX) $(ARGS) main.o set.o autotest.o -o $(OUT)

main.o: src/main.cpp includes/autotest.h
	$(CXX) $(ARGS) -c src/main.cpp -o main.o

autotest.o: src/autotest.cpp includes/autotest.h includes/set.h
	$(CXX) $(ARGS) -c src/autotest.cpp -o autotest.o

set.o: src/set.cpp includes/node.h includes/set.h
	$(CXX) $(ARGS) -c src/set.cpp -o set.o

clean:
	rm -f *.o $(OUT)

rebuild: clean build

run: build
	./$(OUT)