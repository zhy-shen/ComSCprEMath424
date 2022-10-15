CC = gcc
FFLAGS = -O3 -Wall -std=c99 -pg
LFLAGS = -lm -pg
OBJECTS = main.o \
trimatrix.o Hessenberg.o QRA.o matrix.o QRdecomp.o GetShift.o FindZero.o main_transpose.o main_throughput.o main_QRAlg.o main_matrix.o

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
	@echo " main_transpose.o"
	@echo " main_throughput.o"
	@echo " main_QRAlg.o "
	@echo " main_matrix.o"
	@echo " clean: removes *.o, *.txt, and *.exe files"

