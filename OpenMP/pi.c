#include <stdio.h> 
#include <omp.h>


static long num_steps = 100000;
double step;
void main (){ 
    int i; double x, pi, sum = 0.0;
    step = 1.0/(double) num_steps;
    
    #pragma omp parallel
    {
        #pragma omp for private(x,i) reduction(+:sum)
        for (i=0;i< num_steps; i++){
            #pragma omp critical
            x = (i+0.5)*step;
            sum = sum + 4.0/(1.0+x*x);
        }       
    }
    pi = step * sum;
    printf("%e \n",pi);
}