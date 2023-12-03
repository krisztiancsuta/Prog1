#include <stdlib.h>
#include <stdio.h>
//#include "debugmalloc.h"
// letrehozok egy listatipust

typedef struct listelem
{
    int data;
    struct listelem *next;
} listelem;

// letrehozok egy  ures listat 2 strazsasto

void listabejaras(listelem *head)
{
    listelem *p = head;

    for (listelem *p2 = head; p2 != NULL; p2 = p2->next)
        ;

    while (p != NULL)
    {
        p = p->next;
    }
}
// head -> p -> elem1 -> elem2 -> NULL;
listelem *pushfront(listelem *head, int data)
{
 
    listelem *p = malloc(sizeof(listelem));
    p->data = data;
    p->next = head;
    head = p;
    return head;
}

void pushfront2(listelem **head, int data)
{
    listelem *p = malloc(sizeof(listelem));
    p->data = data;
    p->next = *head;
    *head = p;
}

listelem *popfront(listelem *head)
{
    listelem *p;
    if (head != NULL)
    {
        p = head;
        head = head->next;
        free(p);
    }
    return head;
}

void popfront2(listelem **head)
{
    listelem *p;
    if (head != NULL)
    {
        p = *head;
        *head = (*head)->next;
        free(p);
    }
}

listelem *push2end(listelem *head, int newdata)
{
    listelem *p ;
    for ( p = head; p->next != NULL; p = p->next);
    p->next = malloc(sizeof(listelem));
    p->next->data = newdata;
    p->next->next = NULL;
    return head;
}

listelem *insert(listelem *head, int data){
    listelem *p = head;
    listelem *q = p->next;
    listelem *new = malloc(sizeof(listelem));
    while(q->data < data && p->next->next != NULL){
        p = p->next;
        q = q->next;
    }
    new->data = data;
    new ->next = q;
    p->next = new;
    return head;
  
}

listelem *createlist(void){
    listelem *head = malloc(sizeof(listelem));
    listelem *tail = malloc(sizeof(listelem));
    head->next = tail;
    tail->next = NULL;
    return head;
}

listelem *poplast(listelem *head){
    listelem *p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;

}

listelem *swicth(listelem *head){
    
    listelem *p = head->next;
    listelem *q = p->next;
    head->next = q;
    p->next = q->next;
    q->next = p;
    return head;
}
int main()
{

    listelem *head = createlist();

    pushfront2(&head,0);//strazsa
    pushfront2(&head,3);
    pushfront2(&head,1);
    pushfront2(&head,0);//strazsa
    head = insert(head,2);
    head = swicth(head);   
    for(listelem *p = head; p->next!= NULL && p->next->next!= NULL; p = p->next){
        printf("%d ",p->data);
    }
   

    return 0;
}
 