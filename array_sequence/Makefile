CXX     = g++
ARGS    = -Wall -std=c++17

OUT     = run

build: main.o array_sequence.o autotest.o
	$(CXX) $(ARGS) main.o array_sequence.o autotest.o -o $(OUT)

main.o: src/main.cpp includes/autotest.h
	$(CXX) $(ARGS) -c src/main.cpp -o main.o

autotest.o: src/autotest.cpp includes/autotest.h includes/array_sequence.h
	$(CXX) $(ARGS) -c src/autotest.cpp -o autotest.o

array_sequence.o: src/array_sequence.cpp includes/array_sequence.h
	$(CXX) $(ARGS) -c src/array_sequence.cpp -o array_sequence.o

clean:
	rm -f *.o $(OUT)

rebuild: clean build

run: build
	./$(OUT)