#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include "debugmalloc.h"
typedef unsigned char byte;   // 0-255;
typedef unsigned short int16; // 0-65635
typedef unsigned int int32;   // 0-4294967295

// katalogus
// 2 byte fajlok szama
// 4 byte 1. fajl merete
// n char + 1byte

typedef struct file
{
    int32 size;
    char name[256];
} file;

typedef struct catalouge
{
    int16 filecount;
    file *files;
} catalogue;

int copy_info(FILE *pfp, catalogue cat)
{
    for (int i = 0; i < cat.filecount; i++)
    {
        if (fwrite(&cat.files[i].size, sizeof(int32), 1, pfp) == 0)
            return 0;
        if (fwrite(&cat.files[i].name, strlen(cat.files[i].name) + 1, 1, pfp) == 0)
            return 0;
    }
    return 1;
}
int copy_data(FILE *fp, FILE *pfp, file current_file)
{
    for (int i = 0; i < current_file.size; i++)
    {
        byte b;
        if (fread(&b, sizeof(byte), 1, fp) == 0)
            return 0;
        if (fwrite(&b, sizeof(byte), 1, pfp) == 0)
            return 0;
    }
    return 1;
}

int pack(char **argv, int argc, void **cp)
{
    char pfname[255];

    strcpy(pfname, argv[2]);

    catalogue cat;
    cat.filecount = 0;
    cat.files = malloc(sizeof(file) * (argc - 3)); // argc - 3 mert az elso 3 parameter a programnev, a parancs es a packedfile neve
    *cp = cat.files;
    if (argc >= 3)
        for (int i = 0; i < argc - 3; i++)
        {

            strcpy(cat.files[i].name, argv[3 + i]);
            cat.filecount++;
            // printf("%s ", cat.files[i].name);
        }
    else
        return 0;

    FILE *pfp = fopen(pfname, "wb");
    if (pfp == NULL)
        return 0;
    fwrite(&cat.filecount, sizeof(int16), 1, pfp); // fajlok szama

    for (int i = 0; i < cat.filecount; i++)
    {
        FILE *fp = fopen(cat.files[i].name, "rb");
        if (fp == NULL)
            return 0;
        fseek(fp, 0, SEEK_END);
        cat.files[i].size = ftell(fp);
        fclose(fp);
    }

    if (copy_info(pfp, cat) == 0)
        return 0;

    for (int i = 0; i < cat.filecount; i++)
    {
        FILE *fp = fopen(cat.files[i].name, "rb");
        if (fp == NULL)
            return 0;

        if (copy_data(fp, pfp, cat.files[i]) == 0)
            return 0;
        fclose(fp);
    }

    fclose(pfp);

    return 1;
}

char *unit(long long int size, int *divider)
{
    char *units = malloc((3 + 1) * sizeof(char));
    if (size < pow(2, 10))
    {
        strcpy(units, "B");
        *divider = 1;
        return units;
    }
    else if (size < pow(2, 20))
    {
        strcpy(units, "KiB");
        *divider = pow(2, 10);
        return units;
    }
    else if (size < pow(2, 30))
    {
        strcpy(units, "MiB");
        *divider = pow(2, 20);
        return units;
    }
    else if (size < pow(2, 40))
    {
        strcpy(units, "GiB");
        *divider = pow(2, 30);
        return units;
    }
    return NULL;
}

int list(char **argv, void **cp)
{
    catalogue cat;
    char filename[255];
    strcpy(filename, argv[2]);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
        return 0;

    fread(&cat.filecount, 2, 1, fp);

    cat.files = malloc(cat.filecount * sizeof(file));
    *cp = cat.files;
    for (int i = 0; i < cat.filecount; i++)
    {
        char temp;
        fread(&cat.files[i].size, sizeof(int32), 1, fp);
        int j = 0;
        do
        {
            fread(&cat.files[i].name[j], sizeof(char), 1, fp);
        } while (cat.files[i].name[j++] != '\0');
        cat.files[i].name[j] = '\0';
    }

    for (int i = 0; i < cat.filecount; i++)
    {
        int divider;
        char *actual = unit(cat.files[i].size, &divider);

        printf("%s (%d %s)\n", cat.files[i].name, cat.files[i].size / divider, actual);
        free(actual);
    }

    return 1;
    fclose(fp);
}

int dataoffset(FILE *read)
{
    char null = '0';
    int filecnt = 0;
    // megkeresem a data kezdetenek cimet;
    fread(&filecnt, sizeof(int16), 1, read);

    int offset = 6; // offset a a vegerol
    fseek(read, 6, SEEK_SET);
    for (int i = 0; i < filecnt; i++)
    {
        while (null != '\0')
        {
            null = fgetc(read);
            offset++;
        }
        offset += 4;
        null = '0';
        fseek(read, 4, SEEK_CUR);
    }
    offset -= 4;
    return offset;
}

int search_file_in_file(FILE *read, char *filename, file *foundfile, int32 **sizes, char **data)
{

    char null = '0';
    file tosearch = {0, "0"};
    int filecnt = 0;

    int x = dataoffset(read);

    fseek(read, 0, SEEK_SET);
    fread(&filecnt, sizeof(int16), 1, read);

    *sizes = (int32 *)malloc(sizeof(int32) * filecnt);

    int offset = 6; // offset a a vegerol
    fseek(read, 2, SEEK_SET);
    fread(&(*sizes)[0], 4, 1, read);

    fseek(read, 6, SEEK_SET);
    int j = 0;
    int i;
    for (i = 0; i < filecnt; i++)
    {
        while (null != '\0')
        {
            null = fgetc(read);
            tosearch.name[j] = null;
            j++;
            offset++;
        }
        tosearch.name[j] = '\0';
        // printf("%s",tosearch.name);
        if (strcmp(filename, tosearch.name) == 0)
            break;

        j = 0;
        tosearch.name[0] = '\0';
        null = '0';
        offset += 4;
        if (offset <= x)
            fread(&(*sizes)[i + 1], 4, 1, read);
        // ffseek(read,4,SEEK_CUR);
        // printf("%d\n",(*sizes)[i+1]);
    }

    // printf("%d\n", offset);
    // printf("i = %d\n", i);
    // printf("%lu\n", strlen(tosearch.name));

    fseek(read, offset - 5 - strlen(tosearch.name), SEEK_SET);
    fread(&tosearch.size, sizeof(int32), 1, read);
    // printf("%d\n", x);
    // printf("%d=size", tosearch.size);

    if (null == '0')
        return 0;

    *data = (char *)malloc(tosearch.size);
    fseek(read, x, SEEK_SET);

    for (j = 0; j < i; j++)
    {
        fseek(read, (*sizes)[j], SEEK_CUR);
    }
    fread(*data, tosearch.size, 1, read);

    *foundfile = tosearch;

    return 1;
}

int unpack_file(FILE *read, char *filename)
{
    file readf;
    int32 *sizes;
    char *data;
    FILE *fp;
    if (fp == NULL)
    {
        printf("Unable to unpack <%s>", filename);
        return 0;
    }

    if (search_file_in_file(read, filename, &readf, &sizes, &data) == 1)
    {
        fp = fopen(filename, "wb");
        if (fp == NULL)
            return 0;
        fwrite(data, readf.size, 1, fp);
        free(sizes);
        free(data);
    }
    else
    {
        printf("Unable to unpack %s", filename);
        free(sizes);
        return 0;
    }

    fclose(fp);

    return 1;
}

void unpack_all(char **argv)
{   
    catalogue cat;

    FILE *read = fopen(argv[2], "rb");
    int x = dataoffset(read);

    fseek(read,0,SEEK_SET);
    fread(&cat.filecount, 2, 1, read);
    
    
    cat.files = malloc(cat.filecount * sizeof(file));
    int offset = 6; // offset a a vegerol
    fseek(read, 6, SEEK_SET);

    char null = '0';
    int j = 0;
    int i;
    
    for (i = 0; i < cat.filecount; i++)
    {
        while (null != '\0')
        {
            null = fgetc(read);
            cat.files[i].name[j] = null;
            j++;
            offset++;
        }
        cat.files[i].name[j] = '\0';
        // printf("%s",tosearch.name);
        j = 0;

        null = '0';
        offset += 4;
        if (offset <= x)
            fseek(read, 4, SEEK_CUR);
        // printf("%d\n",(*sizes)[i+1]);
    }
    fclose(read);
    for (i = 0; i < cat.filecount; i++)
    {
        FILE *read = fopen(argv[2], "rb");
        unpack_file(read, cat.files[i].name);
        fclose(read);
    }
    free(cat.files);
    
}
void printHelp()
{
    printf("usage: program command\n");
    printf("commands:\n");
    printf("    pack <packed_file> <file_1> [<file_2> ...] Pack file_1, file_2, etc. into packed_file\n");
    printf("    list <packed_file> List the packed files in the archive\n");
    printf("    unpack <packed_file> <file_1> [<file_2> ...] Unpack the selected files\n");
    printf("    unpack <packed_file> Unpack all files\n");
}
void unpack(char **argv, int argc)
{   
    int i;

    if (argc > 3)
    {
        for (i = 3; i < argc; i++)
        {
            FILE *read = fopen(argv[2], "rb");
            unpack_file(read, argv[i]);
            fclose(read);
        }
    }
    else
    {   
        unpack_all(argv);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printHelp();
        return 1;
    }

    if (strcmp(argv[1], "pack") == 0 && argc > 3)
    {
        void *p;
        if (pack(argv, argc, &p) != 1)
        {
            printf("Failed to pack");
            free(p);
            return 1;
        }
        free(p);
    }
    else if (strcmp(argv[1], "list") == 0 && argc == 3)
    {
        void *p;
        if (list(argv, &p) != 1)
        { // beolvassa a csomagolt fajl nevet
            printf("Failed to list");
            return 1;
        }
        free(p);
    }
    else if (strcmp(argv[1], "unpack") == 0 && argc > 2)
    {
        unpack(argv, argc);
    }
    else
    {
        printHelp();
        return 1;
    }

    return 0;
}