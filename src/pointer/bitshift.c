#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define TRUE 	0
#define FALSE 	1

bool is_arithmetic_right_shift( int num );
size_t c_strlen( char *str );
int find_char( char **strings, char ch );

int main(int argc, char *agv[]) {
	char *str = "hello world";
	size_t len = c_strlen( str );
	printf( "len(str) = %zu\n", len );

	char *strings[] = {
		"Hello, World",
		"pretty girl",
		NULL
	};
	int rst = find_char( strings, 'z' );
	printf( "rst = %d\n", rst );


	int a;
	*&a = 25;
	printf( "a = %d, *a=%d\n", a, *&a );

	bool result = is_arithmetic_right_shift( - 1 );
	printf( "%#X\n", result );
	if ( result == true ) {
		printf( "有符号数右移执行的是算术右移\n" );
	}
	return EXIT_SUCCESS;
}

bool is_arithmetic_right_shift( int num ) {
	if (num >= 0 ) num = -1;
	int shifted = num >> 1;
	printf( "%#X\n", shifted );
	printf( "%#X\n", num );
	return shifted < 0;
}

size_t c_strlen( char *str ) {
	size_t len = 0;
	while( *str++ != '\0' ) {
		len++;
	}
	return len;
}

int find_char( char **strings, char ch ) {
	assert(strings != NULL);
	while( *strings != NULL ) {
		char *string = *strings++;
		while( *string != '\0' ) {
			// *间接操作符优化级比++运算符低
			if( *string++ == ch ) {
				return TRUE;
			}
			// string++;
		}
		// strings++;
	}
	return FALSE;
}