#include<stdio.h>

extern int fibonacci(int x);

int main(int argc,char **argv){
	int result=0;
	int number=0;
	scanf("%d",&number);
	result = fibonacci(number);
	printf("The fibonacci sequence at %d is: %d\n", number, result);
	return result & 0x000000ff;
}
