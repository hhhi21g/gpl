# 1. make

all: mini

mini: main.c mini.l mini.y
	lex -o mini.l.c mini.l
	yacc -d -o mini.y.c mini.y
	gcc -g3 main.c mini.l.c mini.y.c -o mini

# 2. make run test=name

run: $(test).m
	./mini $<

# 3. make clean
clean:
	rm -fr *.l.* *.y.* mini
