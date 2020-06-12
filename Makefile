CC = gcc
CFLAGS = -Wall
SOURCES = $(addprefix src/, logseeker.c)

all: bin/logseeker

bin/logseeker: $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $(SOURCES)

install:
	cp ./bin/logseeker /usr/local/bin/logseeker