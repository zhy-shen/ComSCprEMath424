CC = gcc
FFLAGS = -O3 -Wall -std=c99
LFFLAG =
OBJECTS = main.o \
trimatrix.o Hessenberg.o QRA.o matrix.o QRdecomp.o GetShift.o FindZero.o

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
	@echo " trimatrix.o"
	@echo " Hessenberg.o"
	@echo " QRA.o"
	@echo " matrix.o"
	@echo " QRdecomp.o"
	@echo " GetShift.o"
	@echo " FindZero.o"
	@echo " clean: removes *.o, *.txt, and *.exe files"

