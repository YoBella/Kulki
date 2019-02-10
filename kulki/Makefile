CC=gcc
GTKFLAGS = $(shell pkg-config gtk+-3.0 --cflags --libs)
CFLAGS = -std=c11

NAME=kulkix

DEPS = funkcje.h
SRC = kulki_main.c zbudujplansze.c menuglowne.c kolejnekulki.c
OBJ = kulki_main.o zbudujplansze.o menuglowne.o kolejnekulki.o

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GTKFLAGS)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(GTKFLAGS)

clean:
		rm -f $(OBJ) 
