CXX     = g++
ARGS    = -Wall -std=c++17

OUT     = run

build: main.o sequence_adt.o autotest.o
	$(CXX) $(ARGS) main.o sequence_adt.o autotest.o -o $(OUT)

main.o: src/main.cpp includes/autotest.h
	$(CXX) $(ARGS) -c src/main.cpp -o main.o

autotest.o: src/autotest.cpp includes/autotest.h includes/sequence_adt.h
	$(CXX) $(ARGS) -c src/autotest.cpp -o autotest.o

sequence_adt.o: src/sequence_adt.cpp includes/node.h includes/sequence_adt.h
	$(CXX) $(ARGS) -c src/sequence_adt.cpp -o sequence_adt.o

clean:
	rm -f *.o $(OUT)

rebuild: clean build

run: build
	./$(OUT)