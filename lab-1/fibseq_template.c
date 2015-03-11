#include<stdio.h>

extern int fibonacci(int);

int fib_high(int x){
	int result = 0;
	result = fibonacci(x);
	return (result &0x0000ff00)>>8;
}

int fib_low(int x){
	int result = 0;
	result = fibonacci(x);
	return result &0x000000ff;
}
