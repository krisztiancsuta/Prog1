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
    if (p == NULL)
    {
        socks = new_elem;
        new_elem->next = NULL;
        return;
    }
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
    list_ptr p = kosar->next;

    while (p != NULL && p->next != NULL)
    {
        if (p->size == new_elem.size && strcmp(p->color, new_elem.color) == 0)
            cnt++;
        p = p->next;
    }

    return cnt;
}

void remove_odd(list_ptr kosar1, list_ptr kosar2)
{

    list_ptr p = kosar1->next;
    list_ptr q = kosar1->next;
    while (q != NULL)
    {
        if ((npairs(q, *q) + 1) % 2 != 0)
        {
            list_ptr tmp = p;
            p = p->next;
            tmp->next = NULL;
            link_back(tmp, kosar2);
        }
        else
        {
            p = p->next;
        }
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
    list_elem sock3 = {10, "red", NULL};
    list_elem sock4 = {11, "green", NULL};

    link_back(&sock1, head1);
    link_back(&sock2, head1);
    link_back(&sock3, head1);
    link_back(&sock4, head1);

    // Páratlan zoknik eltávolítása és áthelyezése a második listába
    remove_odd(head1, head2);

    // Kiírjuk a második lista tartalmát
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