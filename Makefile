CC=g++
CFLAGS=-Wall -Wextra
EXEC=./tp1
TMPOUT=lista.testresult

$(EXEC): src/main.cpp graph.o distribution-center.o
	$(CC) $(CFLAGS) src/main.cpp graph.o distribution-center.o -o $(EXEC)

graph.o: src/graph/graph.cpp
	$(CC) $(CFLAGS) -c src/graph/graph.cpp -o graph.o

distribution-center.o: src/distribution-center/distribution-center.cpp
	$(CC) $(CFLAGS) -c src/distribution-center/distribution-center.cpp -o distribution-center.o

test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)

clean:
	rm -rf .graph
