#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

void store_in_array(char *str, int *array);
void print_array(int *num, int len);
char *strrev(char *str);
int *multiplication(int *num1, int *num2, int len1, int len2);
int _putchar(char c);
int _strlen(char *s);
void init_zero(int *a, int len);
int *myalloc(int *n, int size);
void print_error(void);
void check_input(char* argv[]);

#endif