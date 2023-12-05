#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct l
{
    int size;
    char color[21];
    struct l *next;

} list_elem, *list_ptr;

void link_back(list_ptr new_elem, list_ptr socks)
{
    list_ptr p = socks; // strazsa miatt
   
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = new_elem;
    new_elem->next = NULL;
}

int npairs(list_ptr kosar, list_elem new_elem)
{
    int cnt = 0;
    list_ptr p = kosar;

    while (p != NULL)
    {
        if (p->size == new_elem.size && strcmp(p->color, new_elem.color) == 0)
            cnt++;
        p = p->next;
    }

    return cnt;
}

void remove_odd(list_ptr kosar1, list_ptr kosar2)
{
    list_ptr p = kosar1;
    list_ptr q = kosar1->next;
    while (q != NULL)
    {
        if(npairs(kosar1,*q)%2 != 0){
            p->next = q->next;
            link_back(q,kosar2);

        }
        p = p->next;
        q = q->next;
    }
    
}
int main()
{
    // Létrehozzuk a listákat
    list_elem *head1 = (list_elem *)malloc(sizeof(list_elem));
    head1->next = NULL;
    list_elem *head2 = (list_elem *)malloc(sizeof(list_elem));
    head2->next = NULL;

    // Példa zoknik létrehozása és hozzáadása az első listához
    list_elem sock1 = {10, "red", NULL};
    list_elem sock2 = {10, "blue", NULL};
    list_elem sock3 = {15, "green", NULL};
    list_elem sock4 = {8, "yellow", NULL};
    list_elem sock5 = {12, "black", NULL};
    list_elem sock6 = {10, "white", NULL};
     list_elem sock11 = {15, "green", NULL};
      list_elem sock12 = {15, "green", NULL};
       list_elem sock13 = {15, "green", NULL};
    list_elem sock7 = {15, "orange", NULL};
    list_elem sock8 = {8, "pink", NULL};
    list_elem sock9 = {12, "gray", NULL};
    list_elem sock10 = {10, "brown", NULL};


    link_back(&sock1, head1);
    link_back(&sock2, head1);
    link_back(&sock3, head1);
    link_back(&sock4, head1);
    link_back(&sock5, head1);
    link_back(&sock6, head1);
    link_back(&sock7, head1);
    link_back(&sock8, head1);
    link_back(&sock9, head1);
    link_back(&sock10, head1);
    link_back(&sock11, head1);
    link_back(&sock12, head1);
    link_back(&sock13, head1);

    


    printf("Páros zoknik száma: %d\n", npairs(head1, sock1));
    printf("Páros zoknik száma: %d\n", npairs(head1, sock2));
 
    // Páratlan zoknik eltávolítása és áthelyezése a második listába
    remove_odd(head1, head2);

    // Kiírjuk a második lista tartalmát
    list_ptr p2 = head1->next;
    while (p2 != NULL)
    {
        printf("Size: %d, Color: %s\n", p2->size, p2->color);
        p2 = p2->next;
    }
    printf("---------------\n");
    list_ptr p = head2->next;
    while (p != NULL)
    {
        printf("Size: %d, Color: %s\n", p->size, p->color);
        p = p->next;
    }

    // Felszabadítjuk a memóriát
    free(head1);
    free(head2);

    return 0;
}