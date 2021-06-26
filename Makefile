cprimes: main.c
	gcc -Ofast -flto -fopenmp main.c -o cprimes -Wall -Wextra -Wpedantic
