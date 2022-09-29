CC = gcc
FFLAGS = -O3 -Wall
LFFLAG =
OBJECTS = main.o \
	Option.o \
	DisplayOptions.o \
	Push.o \
	Pop.o \
	Peek.o \
	DisplayStack.o \
	GetStackSize.o \
	DeleteStack.o

.PHONY: clean help

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
	@echo " Option.o"
	@echo " DisplayOptions.o"
	@echo " Pop.o"
	@echo " Peek.o"
	@echo " DisplayStack.o"
	@echo " GetStackSize.o"
	@echo " DeleteStack.o"
	@echo " clean: removes *.o, *.txt, and *.exe files"
