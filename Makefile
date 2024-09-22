CFLAGS = -Wall -Wextra -std=c11 -pedantic -ggdb 

main : main.c
			gcc $(CFLAGS) -o sort  visualiser.c algo.c main.c -lraylib -lm -lpthread -ldl -lrt -lX11
			./sort