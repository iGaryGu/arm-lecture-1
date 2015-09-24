#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fibseq_template.c"
#define MAX 46
#define Iter 1000

extern int fibonacci(int x, int a, int b);
int (*p[2]) (int)={fib_low, fib_high};

int main(int argc, char **argv)
{
    struct timespec tt1, tt2;
    double sec = 0.0;
    int number=0;
    int result=0;
    if(argc == 2) {
        if (atoi(argv[1]) == 2) {    //timing statistics
	    int i, j;
	    double temp;
	    FILE *fpr = fopen("timing.txt","w");
	    for (i = 0; i <= MAX; i++) {
		temp = 0.0;
		for (j = 0; j < Iter; j++) {
		    clock_gettime(CLOCK_REALTIME,&tt1);
		    result = fibonacci(i, 0, 1);
		    clock_gettime(CLOCK_REALTIME,&tt2);
		    temp += ((double)tt2.tv_nsec - (double)tt1.tv_nsec);
		} 
		printf("The fibonacci sequence at %d is: %d\n", i, result);
		sec = temp/(double)Iter;
		fprintf(fpr,"%d %lf\n",i,sec);
	    }
	    fclose(fpr);
        } else {
	    scanf("%d",&number);
	    result = p[atoi(argv[1])](number);
	    return result;
        }
    } else {
	scanf("%d",&number);
        result = fibonacci(number, 0, 1);
	printf("The fibonacci sequence at %d is: %d\n", number, result);
    }
}

