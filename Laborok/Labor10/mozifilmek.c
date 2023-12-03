#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<string.h>


typedef struct
{
    char title[20];
    double popularity; // 1..5
} movie;

typedef struct l
{
    movie m;
    struct l *next;
} listelem;
void print_movies(listelem *head)
{
    // head -> 1 -> 2 -> tail -> NULL
    listelem *p = head;
    while (p->next != NULL && p->next->next != NULL)
    {
        char rating[5 + 1];
        int i;
        for (i = 0; i < round(p->next->m.popularity); i++)
        {
            rating[i] = '*';
        }
        rating[i] = '\0';
        printf("%-20s (%-5s)\n", p->next->m.title, rating);
        p = p->next;
    }
}

void insert_movie(listelem *head, char title[], double rating)
{
    // head -> 1 -> 3 -> tail -> NULL
    //insert 2 p -> q -> 3
    listelem *p = head;
    while(p->next != NULL && p->next->next != NULL && rating < p->next->m.popularity)
    {
        p = p->next;
    }
    listelem *temp = p->next;
    listelem *q = malloc(sizeof(listelem));
    q->m.popularity = rating;
    strcpy(q->m.title,title); 
    q->next = temp;
    p->next = q;

}

int main()
{

    return 0;
}