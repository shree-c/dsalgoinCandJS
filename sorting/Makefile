sorting: utilityfuns.o
	cc ./mergesort.c ./utilityfuns.o -o merge.bin
	cc ./quicksort.c ./utilityfuns.o -o quick.bin
	cc ./insertionsort.c ./utilityfuns.o -o ins.bin
	cc ./shellsort.c ./utilityfuns.o -o shell.bin
	cc ./bubblesort.c ./utilityfuns.o -o bubble.bin
	cc ./selectionsort.c ./utilityfuns.o -o sel.bin

utilityfuns.o:
	cc -c utilityfuns.c
clean:
	rm *.bin
