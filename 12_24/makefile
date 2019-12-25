.PHONY:all
all:reader writer
reader:read.c
	gcc $^ -g -o $@
writer:writer.c
	gcc $^ -g -o $@

Pipe:Pipe.c
	gcc $^ -g -o $@
Iobase:Iobase.c
	gcc $^ -g -o $@
myshell:myshell.c
	gcc $^ -g -o $@

.PHONY:clean
	clean:
	rm myshell
