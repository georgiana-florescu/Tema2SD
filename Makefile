build: minimax

minimax: main.o  tree.o and_or_tree.o minimax_tree.o
	gcc main.o  tree.o and_or_tree.o minimax_tree.o -o minimax

main.o: main.c

tree.o: tree.h tree.c

and_or_tree.o: and_or_tree.h and_or_tree.c

minimax_tree.o: minimax_tree.h minimax_tree.c

run:
	./minimax

memcheck:
	valgrind ./minimax

make clean:
	rm -f *.o minimax
