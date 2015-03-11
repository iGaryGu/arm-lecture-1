#include <stdio.h>
#include <stdlib.h>
#include "fibseq_template.c"

extern int fibonacci(int x);
int (*p[2]) (int)={fib_low,fib_high};

int main(int argc, char **argv)
{
  int number=0;
  int result=0;
  scanf("%d",&number);
  if(argc==2){
	  result = p[atoi(argv[1])](number);
	  return result;
  }else{
  	result = fibonacci(number);
  	printf("The fibonacci sequence at %d is: %d\n", number, result);
  }
}

