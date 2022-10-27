CC = gcc
FFLAGS = -Wall -std=c99 -fopenmp
LFLAGS = -lgomp -lm
OBJECTS = int_omp2.o

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) *. exe
