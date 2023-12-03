
#include <stdio.h>
#include <stdlib.h>

typedef struct _listelem
{
    int a;
    struct _listelem *next;
} listelem;

/*
Írj függvényt, mely egy egészeket tároló, egyirányban láncolt,
kétstrázsás (elöl, hátul) láncolt listát kap paraméterként, és
az egymást követő elempárok sorrendjét felcseréli!

Például:S-1-2-3-4-5-S -> 2-1-4-3-5

A függvény neve legyen reverse_pairs. A függvénynek az eredeti
listaelemeket kell újraláncolnia, nem pedig csak az azokban tárolt
értékeket kicserélni. A listaelemek az alábbi típusúak (az ellenőrzőbe ezt nem szabad bemásoln*/

void reverse_pairs(listelem *head)
{
    listelem *kezds = head;
    listelem *vegs = head;
    int i = 0;
    while (1)
    {
        // 0 3 2 1 0
        // 0 2
        if ( vegs->next != NULL && vegs->next->next != NULL && vegs->next->next->next != NULL)
        {
           
            listelem *temp2;
            listelem *temp = vegs->next; // 3
            vegs->next = temp->next;     // 2
            temp2 = vegs->next;          // 2
            temp->next = temp2->next;    // 3
            vegs->next->next = temp;     // 1

        }
        else if (vegs->next == NULL)
        {
            break;
        }
        else if (vegs->next->next == NULL)
        {
            break;
        }
        else if (vegs->next->next->next == NULL)
            break;
        vegs = vegs->next->next;
        i++;
    }
}

listelem *list_from_array(int t[], int n)
{
    // Létrehozunk egy új fej- és farokstrázsát.
    listelem *head = (listelem *)malloc(sizeof(listelem));
    listelem *tail = (listelem *)malloc(sizeof(listelem));

    // Inicializáljuk a strázsákat.
    head->next = tail;
    tail->next = NULL;

    // Az utolsó elem kezdetben a fejstrázsa.
    listelem *last = head;

    for (int i = n - 1; i >= 0; i--)
    {
        listelem *new = (listelem *)malloc(sizeof(listelem));
        new->a = t[i];
        new->next = last->next; // Az új elem a fejstrázsa utáni elemre mutat.
        last->next = new;       // Az utolsó elem most az új elemre mutat.
        last = new;             // Frissítjük az utolsó elemet.
    }

    // Az utolsó elem a farokstrázsa előtt legyen.
    last->next = tail;

    // Visszatérünk a fejstrázsával.
    return head;
}

int main()
{
    int tomb[] = {1, 2, 3, 4, 5};
    listelem *list = list_from_array(tomb, 5);

    reverse_pairs(list);
    while (list != NULL)
    {

        printf("%d ", list->a);
        list = list->next;
    }
    //  Elkezdjük a listát a fej strázsa utáni első valódi elemtől.
}