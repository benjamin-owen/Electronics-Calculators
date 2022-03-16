CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
TESTS = #-DDEBUG
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = calc
OBJS =  hw14.o huffman.o output.o utility.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

resistor-combination: resistor-combination/resistor-combination.o helper.o
	$(GCC) resistor-combination.o helper.o -o $(EXEC)

# $(EXEC): $(OBJS) huffman.h output.h utility.h
# 	$(GCC) $(OBJS) -o $(EXEC) 

all: $(EXEC)

test: $(EXEC)
	./$(EXEC) 10 10 10 10

memory: $(EXEC)
	$(VALGRIND) --leak-check=full --log-file=memtest/log1 ./$(EXEC) 10 10 10 10

%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f memtest/log*