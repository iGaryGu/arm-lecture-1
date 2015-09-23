#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 46
#define Iter 1000
extern int fibonacci(int x);

int main(int argc, char **argv)
{
    int number=0;
    int result=0;
    double sec = 0.0;
    struct timespec tt1, tt2;
    if (atoi(argv[1]) == 1) {    // timing statistic 
        int i, j;
        double temp;
        FILE *fpr = fopen("timing.txt","w");
        for (i = 0; i <= MAX; i++) {
            temp = 0.0;
            for (j = 0; j < Iter; j++) {
                clock_gettime(CLOCK_REALTIME,&tt1);
                result = fibonacci(i);
                clock_gettime(CLOCK_REALTIME,&tt2);
                temp += ((double)tt2.tv_nsec - (double)tt1.tv_nsec);
            } 
            sec = temp/(double)Iter;
            fprintf(fpr,"%d %lf\n",i,sec);
        }
        fclose(fpr);
    } else {
        scanf("%d", &number);
        result = fibonacci(number);
        printf("The fibonacci sequence at %d is: %d\n", number, result);
    }
    return result;
}

