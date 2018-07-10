#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int (*pf)(void);
    long long int rnd;

    srand(time(NULL));
    rnd = rand();
    pf=malloc(1024*sizeof(char));
    memcpy((void*)pf,(void*) rnd, 32);
    pf();
}
