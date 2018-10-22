FILES = hd.c hexdump.c
EXEFILE = hd

build:
	gcc -o $(EXEFILE) -Wall -Wextra $(FILES)

make: build

run: build
	./$(EXEFILE)