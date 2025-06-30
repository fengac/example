#include <stdio.h>
#include <stdlib.h>
#define  MAX_INPUT 50

int main( int argc, char *argv[] ) 
{
	// 4. 分别打印十进制整数，字符串和浮点数
	int a = 12;
	char *str = "hello";
	float f = 12.0f;
	printf( "a = %x, str = %s, f = %f\n", a, str, f );


	// 5. 编写一条scanf语句，它需要读取两个整数，分别保存于quantity和price变量，
	// 然后再读取一个字符串，保存在一个名叫　department 的字符数组中。
	int quantity, price;
	char department[MAX_INPUT];
	int ch;
	printf( "Enter Two Number: " );
	scanf( "%d %d", &quantity, &price );
	while( (ch = getchar()) != '\n' && ch != EOF )
		;
	printf( "Enter String: " );
	fgets( department, MAX_INPUT, stdin );
	printf( "You Input: %s\n", department );

	return EXIT_SUCCESS;
}