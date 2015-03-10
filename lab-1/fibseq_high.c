#include<stdio.h>

extern int fibonacci(int x);

int main(int argc,char **argv){
	int result = 0;
	int number = 0;
	scanf("%d",&number);
	result = fibonacci(number);
	return (result &0x0000ff00)>>8;
}
