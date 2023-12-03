#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
    char letter;
    char code[6];
} codebook_t;

#define CODEBOOKSIZE 37
codebook_t codebook[CODEBOOKSIZE] = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', "-.."}, {'X', "-..-"}, {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."}, {'0', "-----"}, {' ', " "}};

int isin(char a)
{
    for (int i = 0; i < CODEBOOKSIZE; i++)
    {
        if (a == codebook[i].letter)
            return 1;
    }
    return 0;
}

codebook_t encode(char a)
{
    int j;
    codebook_t morze;
    for (int i = 0; i < CODEBOOKSIZE; i++)
    {
        if (a == codebook[i].letter)
            for (j = 0; codebook[i].code[j] != '\0'; j++)
                morze.code[j] = codebook[i].code[j];
    }
    morze.code[j] = '\0';
    return morze;
}

int codelength(char a)
{
    for (int i = 0; i < CODEBOOKSIZE; i++)
    {
        if (a == codebook[i].letter)
            return strlen(codebook[i].code) + 1;
    }
    return 0;
}
/// ABSC BDBS C D E F G
/// Modórzekod ---
// morzkekodok kozt egy space van szavak kozott 3
char* morse(char *s)
{
    int size = 1, i, j;
    for (i = 0; s[i] != '\0'; i++)
        if (isin(s[i]))
        {
            if (s[i] == ' ')
                size += 2;
            else
                size += codelength(s[i]);
        }
   

    char *out = (char *)malloc(size * sizeof(char));
    if(out == NULL)
        return NULL;

    out[0] = '\0';
    codebook_t temp;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (isin(s[i]))
        {
            if (s[i] == ' ')
                strcat(out, "  ");
            else
            {
                temp = encode(s[i]);
                strcat(out, temp.code);
                strcat(out, " ");
            }
        }
    }
    return out;
}
//.- -...    -.-. -..

int main()
{
    char s[] = "A SARA EGY LAN9293727";
    char *s2;
   // codebook_t code = encode(s[0]);
    int p = codelength('E');
    s2 = morse(s);
    
    printf("%s\n", s2);

    return 0;
}
//..- ..--- ... -... ... ----- .--.   -..- -... --.- -.... ....   -... --- -.... ...- ----.