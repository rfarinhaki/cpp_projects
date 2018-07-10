#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct node_t {
    int num;
    struct node_t* right;
    struct node_t* left;
};

typedef struct node_t node;

static volatile int keepRunning = 1;


void insertNode(node **n, int num)
{
    if(*n==NULL){
        *n=(node*)malloc(sizeof(node));
        (*n)->num=num;
        (*n)->left = NULL;
        (*n)->right = NULL;
    }
    else
        if(num > (*n)->num){
            printf("d ");
            insertNode(&((*n)->right), num);
        }
        else{
            printf("e ");
            insertNode(&((*n)->left), num);
        }
}

void insert(node **n, int num){
    printf("%d:", num);
    insertNode(n,num);
    printf("\n");
}

void print(node *n)
{
    if(n==NULL)
        return;
    print(n->left);
    printf("%d ", n->num);
    print(n->right);
}

int main()
{
    char buf[5];
    int num;
    node *root;
    root = NULL;
/*
    insert(&root, 25);
    insert(&root, 10);
    insert(&root, 12);
    insert(&root, 8);
    insert(&root, 9);
    insert(&root, 7);
    insert(&root, 11);
    insert(&root, 13);
    insert(&root, 35);
    insert(&root, 40);
    insert(&root, 32);
    insert(&root, 38);
    insert(&root, 37);
    insert(&root, 39);


    do{
        printf("Num:");
        fscanf(stdin,"%s",buf);
        if((buf[0]>='0' && buf[0]<='9') || buf[0]=='-'){
            num = atoi(buf);
            insert(&root, num);
        }
    }while( (buf[0]>='0' && buf[0]<='9') || buf[0]=='-');
*/
    //for(int i=0; i<1)
    print(root);
    printf("\n");
}
