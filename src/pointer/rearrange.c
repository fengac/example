/**
 * range.c
 * 
 *  这个程序从标准输入中读取输入行并在标准输出中打印这些输入行，
 * 　每个输入行的后面一行是该行内容的一部分。 
 * 
 *  输入行的第一行是一串列标号，串的最后一个以负数结尾
 *  这些列标号成对出现，说明需要被打印的输入行列的范围
 * 
 * 1.去除列标号的个数必须是偶数
 * 2.当字符的列范围超出输入行的末尾时就停止复制，这个判断是假设列范围以递增顺序出现才是正确的，修复它
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  MAX_INPUT 100
#define  MAX_COLS 10

int  read_column_numbers( int columns[], int max );
void show_columns( int columns[], int max );
void rearrange( char *output, char const *input, 
     int n_columns, int const columns[] );

int main( int argc, char *argv[] ) {
    #if 1
    int  columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];

    int n_columns = read_column_numbers( columns, MAX_COLS );

    while ( fgets( input, MAX_INPUT, stdin ) != NULL ) {
        printf( "Origian input: %s\n", input );
        rearrange( output, input, n_columns, columns );
        printf( "Rearranged line: %s\n", output );
    }
    #endif

    return EXIT_SUCCESS;
}

int read_column_numbers( int columns[], int max ) {
    int num = 0;
    int ch;

    printf( "Enter the number of columns: " );
    while ( num < max && scanf("%d", &columns[num]) == 1 
        && columns[num] > 0 ) {
        num++;
    }

    if ( num % 2 != 0 ) {
        puts( "Last column number is not paried" );
        exit( EXIT_FAILURE );
    }

    while ( (ch = getchar()) != '\n' && ch != EOF )
        ;
        
    return num;
}

void show_columns( int columns[], int max ) {
    for ( int i = 0; i < max; i++ ) {
        printf( "%d ", columns[i] );
    }
}

void rearrange( char *output, char const *input, 
    int n_columns, int const columns[] ) {
    int col;
    int output_col;
    int len;

    len = strlen( input );
    output_col = 0;

    for ( col = 0; col < n_columns; col = col + 2 ) {
        int nchars = columns[col + 1] - columns[col] + 1;

        if ( columns[col] >= len || output_col == MAX_INPUT - 1 ) {
            break;;
        }

        if ( output_col + nchars > MAX_INPUT - 1 ) {
            nchars = MAX_INPUT - output_col - 1;
        }

        strncpy( output + output_col, input + columns[col], nchars );
        output_col += nchars;
    } 
    output[output_col] = '\0';
}