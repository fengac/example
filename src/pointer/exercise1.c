#include <stdio.h>
#include <stdlib.h>
#define  MAX_INPUT 16

char * show_with_linen_number();
void test();

int main( int argc, char *argv[] ) {
	int line_number = 1;
	char *text = show_with_linen_number();

	printf( "text:\n%s", text );
	printf( " ----------- \n" );
	printf( "%d: ", line_number );

	while ( *text != '\0' ) {
		fputc( *text, stdout );
		if (*text == '\n' ) {
			line_number++;
			printf( "%d: ", line_number );
		}
		// 这里假设行号不会超过10
		text++;
	}

	return EXIT_SUCCESS;
}

// 2. 编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要加上行号。
// 在编写这个程序时要试图让程序能够处理的输入行的长度没有限制。
char * show_with_linen_number() {
	char *buf = (char *)malloc( sizeof(char) * MAX_INPUT );

	int ch;
	size_t len = 0;
	int line_number = 1;

	while ( (ch = getchar()) != EOF ) {
		if ( len > MAX_INPUT - 1 ) {
			char *new_buf = (char *)realloc( buf, sizeof(buf) * 2 );
			buf  = new_buf;
		}
		if ( ch == '\n' ) {
			line_number++;
		}

		buf[len++] = ch;
	}	
	buf[len] = '\n';
	printf( "line_number = %d\n", line_number );
	return buf;
}

// 3. 编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上。它同时计算
// checksum 值，并写在字符后面

// 4. 编写一个程序，一行行地读取输入行，直至到达文件尾。算出每行输入行的长度，然后把最
// 长的那行打印出来。



void test() {
	printf( "缓冲区大小: %d\n", BUFSIZ );
	// 自定义缓冲区(大小可调整)
	char custom_buffer[10];  
    // 设置标准输入流为全缓冲模式，缓冲区大小为4096字节
    // _IOLBF, _IOFBF, _IONBF
    setvbuf( stdin, custom_buffer, _IOLBF, sizeof(custom_buffer) );
    printf( "缓冲区大小: %d\n", BUFSIZ );
    char str[20];
    int i = 0;
    int ch;
    printf( "请输入一行字符串: " );
    while ( (ch = getchar() ) != '\n' && ch != EOF ) {
        str[i++] = ch;
    }
    str[i] = '\0';
    printf( "你输入的字符串是: %s\n", str );
}