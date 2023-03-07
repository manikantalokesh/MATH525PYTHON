CC = gcc
FFLAGS = -O3 -Wall
LFLAGS = -lm
OBJECTS = main.o \
matrix.o \
PowerIteration.o \
RayleighQuotation.o


.PHONY: clean

main.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o main.exe -lm

%.o: %.c
	$(CC) $(FFLAGS) -c $< -lm

clean:
	rm -f $(OBJECTS) main.exe