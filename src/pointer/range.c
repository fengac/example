/**
 * range.c
 * 
 * This program reads a range of integers from the user and prints them.
 * 
 * Usage:   
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
#define MAX_COL_NUMBER 10

int read_col_number(int col_numbers[], int max_col_number);
void print_cols(int col_numbers[], int col_number);
void read_string(char *s, int max_size, int max_col_number, int col_numbers[]);

int main(int argc, char *argv[]) {
    int col_numbers[MAX_COL_NUMBER];
    int col_number = read_col_number(col_numbers, MAX_COL_NUMBER);
    char input[MAX_SIZE];

    printf("Read %d columns\n", col_number);
    
    if (col_number > 0) {
        printf("Columns: ");
        print_cols(col_numbers, col_number);
        printf("\n");
        read_string(input, MAX_SIZE, col_number, col_numbers);
    }

    return 0;
}

int read_col_number(int col_numbers[], int max_col_number) {
    int i = 0;
    int c;

    printf("Enter the number of columns: ");
    while (i < max_col_number && scanf("%d", &col_numbers[i]) == 1 && col_numbers[i] > 0) {
        i++;
    }
    while ((c = getchar()) != '\n' && c != EOF);
        
    return i;
}

void print_cols(int col_numbers[], int col_number) {
    for (int i = 0; i < col_number; i++) {
        printf("%d ", col_numbers[i]);
    }
}

void read_string(char *s, int max_size, int max_col_number, int col_numbers[]) {
    char *p = (char *) malloc(sizeof(char) * max_size);
    printf("Enter a string: ");
    fgets(s, max_size, stdin);
    int index = 0;
    for (int i = 0; i < max_col_number; i = i + 2) {
        int start = col_numbers[i];
        int end = col_numbers[i + 1];
        int len = end - start + 1;
        strncpy(p + index, s + start, len);
        index += len;
    }
    p[index] = '\0';
    printf("Range String: %s", p);
}