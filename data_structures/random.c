#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <getopt.h>

#define DEFSIZE 6

int insert(int *array, int count, int value)
{
    int i;
    for(i=0; i<count; i++){
        if(array[i] == value)
            break;
    }
    if(i==count){
        array[i]=value;
        return 0;
    }else
        return 1;
}

void printArray(int *array, int count){
    for(int i=0; i < count; i++)
        printf("%d ", array[i]);
    printf("\n");
}

void swap(int *array, int posA, int posB)
{
    int tmp;
    tmp = array[posA];
    array[posA]=array[posB];
    array[posB]=tmp;
}

void sortArray(int *array, int count)
{
    int menor, pmenor, i, j;

    for( i=0; i < count-1; i++){
        menor = i;
        for( j=i+1; j < count; j++){
            if(array[j] < array[menor])
                menor = j;
        }
        if(array[menor] != array[i])
            swap(array, i, menor);
    }
}

int getRandom(int limit){
    int num;

    num = ((rand()%10000)*limit)/10000+1;
    //printf("%d ", num);

}

void printUsage(char *name)
{
    printf("Usage:%s -n num -l limite\n", name);

}

int compare(const void *a, const void *b)
{
    if(*(int*)a < *(int*)b ) return -1;
    if(*(int*)a == *(int*)b ) return 0;
    if(*(int*)a > *(int*)b ) return 1;
}

int main(int argc, char **argv)
{
    time_t timer;
    int *array, num, i=0, size=6, limit=60, option;
    int (*fp)(const void*, const void*);
    fp = &compare;

/*    if(argc > 1)
        size = atoi(argv[1]);
    else
        size = DEFSIZE;
*/

    while((option=getopt(argc, argv, "hn:l:")) != -1){
        switch(option){
            case 'n':
                size=atoi(optarg);
                break;
            case 'l':
                limit = atoi(optarg);
                break;
            case 'h':
                printUsage(argv[0]);
                exit(0);
            default:
                printUsage(argv[0]);
                exit(1);
        }
    }

    if(size > limit){
        printf("limit must be greater than size\n");
        exit(2);
    }

    array=malloc(size*sizeof(int));

    time(&timer);
    //printf("Timer:%d", timer);
    srand(time(NULL));

    while(i<size)
    {
        num = getRandom(limit);
        if(insert(array, i, num) == 0)
            i++;
    }
    //printArray(array, SIZE);
    //sortArray(array, size);
    qsort(array, size, sizeof(int), fp);
    printArray(array, size);
    free(array);
}
