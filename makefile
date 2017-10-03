CC=g++
CFLAGS=-I.
DEPS = src/Utils/singleton.h src/States/state.h src/Application/application.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: singleton.o state.o application.o
	g++ -o hellomake main.cpp singleton.o state.o application.o -I.