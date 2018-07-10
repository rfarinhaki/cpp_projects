CC=g++
CFLAGS=-g -Wall -lcrypto
EXEC=blockchain

all: $(EXEC)

blockchain: info.o chain.o block.o main.o
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.cpp %.hpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp 
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper
clean:
	rm *.o

mrproper: clean
	rm $(EXEC)
