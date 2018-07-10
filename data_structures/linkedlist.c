#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int idade;
}pessoa;

typedef struct litem{
    pessoa p;
    struct litem *next;
    struct litem *prev;
}item;


void insert_item(char *nome, int idade, item *head)
{
    item *nitem;

    if(head==NULL)
        return;

    if( strncmp(head->p.nome,"", 20)==0)
    {
        strncpy(head->p.nome,nome, 20);
        head->p.idade=idade;
    }
    else
    {
        if(head->next!=NULL)
            insert_item(nome, idade, head->next);
        else
        {
            head->next=(item*)malloc(sizeof(item));
            nitem = head->next;
            strncpy(nitem->p.nome,nome,20);
            nitem->p.idade = idade;
            nitem->next = NULL;
        }
    }
}

void print_list(item root)
{
        printf("Nome:%s\tidade:%d\n", root.p.nome, root.p.idade);
    if(root.next != NULL)
    {
        print_list(*(root.next));
    }
}

int main()
{
    item head;
    void *test =(void*) 0x4005e0;
    void *t2 = (void*) 0x4006c8;


    memcpy(test, t2,4);
    strncpy(head.p.nome,"",20);
    head.next=NULL;

    insert_item("Ricardo",33, &head);
    insert_item("Gustavo",33, &head);
    insert_item("Joao", 74, &head);
    insert_item("Monica",36, &head);
    insert_item("Antonia", 64, &head);
    print_list(head);
    return 0;
}
