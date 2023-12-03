#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    unsigned id;
    char name[32];
    char message[1002];
} message_t;

int filter_by_name(char *name, char *fname, message_t *messages, int meret)
{
    FILE *fp = fopen(fname, "w");
    if (fp == NULL)
    {
        return 1; // hiba
    }
    for (int i = 0; i < meret; i++)
    {
        if (strcmp(name, messages[i].name) == 0)
        {
            fprintf(fp, "%s\n", messages[i].message);
            fprintf(fp, "\n");
        }
    }
    // itt tortenik az iras
    if (fclose(fp) != 0) // ha nem sikerult a lezaras
        return 1;        // hiba
    return 0;
}

int isreference(char *str, int id)
{ // konkret id-re hivatkozik-e
    // konvert id to char
    char id_str[6 + 1];         // 6 jegyu szam + #
    sprintf(id_str, "#%d", id); // konvertalas
    // keresunk
    while (1)
    {
        char *p = strstr(str, id_str);  // ha nem talalja meg akkor NULL
        if (p == NULL)                  // if(sscanf(p+1, "%d", &a) == 1 && a == id) retrun 1;// alternativ megoldas
            return 0;                   // else str = p+1;
        if (isdigit(p[strlen(id_str)])) // ha talalja meg de nem szam
            str = p + 1;
        else
            return 1;
    }
}

// lancolt listas feladat forditsa meg a lista sorrendjet
typedef struct listelem
{
    int data;
    struct listelem *next;
} listelem_t, *listelem_ptr;

listelem_ptr list_reverse(listelem_ptr head)
{
    listelem_ptr p; // temporary pointer
    listelem_ptr r = NULL;
    while (head != NULL)
    {
        p = r;
        r = head;
        head = head->next;
        r->next = p;
    }
    return r;
}

void f(listelem_ptr family)
{
    listelem_ptr p = family->next;
    while (p != NULL)
    {
        if (p->son != NULL && p->son->son != NULL)
        {
            delete (family, p->son->son);
            p = p->next;
        }
    }
}

void delete(listelem_ptr list, listelem_ptr p)
{
    listelem_ptr q = list;

    while (q->next != p)
    {
        q = q->next;
    }
    q->next = p->next;
    free(p);
}

int main()
{

    return 0;
}