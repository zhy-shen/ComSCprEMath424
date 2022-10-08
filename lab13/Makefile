CC = gcc
FFLAGS = -O3 -Wall -std=c99
LFFLAG =
OBJECTS = main.o \
matrix.o eigensolve.o

.PHONY: clean

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe

%.o: %.c
	$(CC) $(FFLAGS) -c $<

clean:
	rm -f $(OBJECTS) main.exe

help:
	@echo "Valid targets:"
	@echo " main.exe"
	@echo " main.o"
	@echo " matrix.o"
	@echo " eigensolve.o"
	@echo " clean: removes *.o, *.txt, and *.exe files"
