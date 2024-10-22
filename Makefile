all: main.o cpu.o MMU.o
	@gcc main.o cpu.o MMU.o -o exe -Wall
	@rm -r *.o

main.o: main.c
	@gcc main.c -c -Wall

cpu.o: cpu.c
	@gcc cpu.c -c -Wall

MMU.o: MMU.c
	@gcc MMU.c -c -Wall


