CC = gcc

%.o: %.c
	${CC} -c $< -o $@

main: studenti_laureati.o main.c
	${CC} studenti_laureati.o main.c -o $@

clear:
	rm *.o