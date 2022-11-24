CC=g++
CFLAGS=-O0 -g -Wall
DEPS = Alphabet.h DFA.h Grammar.h NFA.h State.h Transition.h utils.h
OBJ = main.o 

SRC = './src/'

compilar:
	g++ $(CFLAGS) $(SRC)*.cc -o Grammar2CNF


%.o: %.cc $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


clean:
	rm -f *.o