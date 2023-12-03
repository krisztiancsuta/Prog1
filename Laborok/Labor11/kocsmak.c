#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct drink
{
    char name[32];
    int price;
    struct drink *next;
} drink;

typedef struct pub
{
    char name[32];
    drink *price_list;
    struct pub *next;
} pub;

pub *read_pubs(char *name)
{
    pub head = {"", NULL, NULL};
    pub **current_pub = &(head.next);
    char buffer[32];
    int price;
    FILE *f = fopen(name, "rt");
    while (fscanf(f, "%31[^\n]\n", buffer) == 1)
    {
        pub *new_pub = (pub *)malloc(sizeof(pub));
        drink **current_drink;
        strcpy(new_pub->name, buffer);
        new_pub->next = NULL;
        *current_pub = new_pub;
        current_pub = &(new_pub->next);
        new_pub->price_list = NULL;
        current_drink = &(new_pub->price_list);
        while (fscanf(f, "%31[^*.]...%d\n", buffer, &price) == 2)
        {
            drink *new_drink = (drink *)malloc(sizeof(drink));
            new_drink->price = price;
            strcpy(new_drink->name, buffer);
            new_drink->next = NULL;
            *current_drink = new_drink;
            current_drink = &(new_drink->next);
        }
        fscanf(f, "%*[^\n]\n");
    }
    fclose(f);
    return head.next;
}

pub *find_cheapest(pub *list, char *alc_drink)
{

    if (list == NULL)
        return NULL;

    pub *cheapest = NULL;
    pub *p = list;
    while (p != NULL)
    {
        drink *d = p->price_list;
        while (d != NULL)
        {
            if (strcmp(d->name, alc_drink) == 0)
            {
                if (cheapest == NULL)
                {
                    cheapest = p;
                    cheapest->price_list->price = d->price;
                }
                else if(cheapest->price_list->price > d->price){
                    cheapest = p;
                    cheapest->price_list->price = d->price;
                }
                
            }
            d = d->next;
        }
        p = p->next;
    }
    return cheapest;
}

int main()
{
    char fname[32] = "test.txt";
    pub *list = read_pubs(fname);
    pub *cheapest = find_cheapest(list, "Heineken");
    if (cheapest != NULL)
        printf("%s %d\n", cheapest->name, cheapest->price_list->price);
    else
        printf("Nincs ilyen ital\n");
    return 0;
}