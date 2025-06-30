#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool is_arithmetic_right_shift( int num );

int main(int argc, char *argv[]) {
	bool result = is_arithmetic_right_shift( - 1 );
	printf( "%#X\n", result );
	return EXIT_SUCCESS;
}

bool is_arithmetic_right_shift( int num ) {
	if (num >= 0 ) num = -1;
	int shifted = num >> 1;
	printf( "%#X\n", shifted );
	printf( "%#X\n", num );
	return shifted < 0;
}