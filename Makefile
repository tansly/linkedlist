CFLAGS=-Wall -pedantic-errors -ggdb
CC=gcc

test: test.o list.o types.vim tags
	$(CC) $(CFLAGS) test.o list.o -o test

test.o: test.c list.h
	$(CC) $(CFLAGS) -c test.c -o test.o

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c -o list.o

tags:
	ctags list.c test.c list.h

types: types.vim
types.vim: *.[ch]
	ctags --c-kinds=gstu -o- *.[ch] |\
		awk 'BEGIN{printf("syntax keyword Type\t")}\
			{printf("%s ", $$1)}END{print ""}' > $@

clean:
	rm -f *.o test tags types.vim
