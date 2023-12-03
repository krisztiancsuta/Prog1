#include <stddef.h>
#include <stdio.h>

#define HEADER_SIZE (sizeof(void *) + sizeof(size_t))

void *free_blocks;        // a szabad lista első elemére mutató pointer, VÁLTOZHAT!!!
void *memory_arena_start; // mindenkor a memória kezdőcímét tartalmazza, NEM VÁLTOZHAT!!!

void *own_malloc(size_t size)
{
    void *found_block = free_blocks;
    void *previously_found = NULL;

    while (found_block != NULL)
    {
        size_t block_size = *((size_t *)found_block + 1);

        if (block_size >= size)
        {
            if (block_size > size + HEADER_SIZE)
            {
                void *block_to_go = (char *)found_block + block_size - size;
                *((size_t *)found_block + 1) = block_size - (size + HEADER_SIZE);
                *((size_t *)block_to_go + 1) = size;
                return (char *)block_to_go + HEADER_SIZE;
            }
            else
            {
                if (previously_found != NULL)
                {
                    *((void **)previously_found) = *((void **)found_block);
                }
                else
                {
                    free_blocks = *((void **)found_block);
                }

                return (char *)found_block + HEADER_SIZE;
            }
        }

        previously_found = found_block;
        found_block = *((void **)found_block);
    }

    return NULL;
}

int areBorderingBlocks(void *block_lower, void *block_higher)
{
    int bordering = 0;
    if (block_lower != NULL && block_higher != NULL && (char *)block_lower + *((size_t *)block_lower + 1) + HEADER_SIZE == block_higher)
    {
        bordering = 1;
    }
    return bordering;
}

void own_defragment()
{
    void *current_block = free_blocks;
    void *previous_block = NULL;

    while (current_block != NULL)
    {
        // Ellenőrizzük az összevonhatóságot a két utolsó blokkra
        void *next_block = *((void **)current_block);

        if (next_block != NULL && areBorderingBlocks(current_block, next_block))
        {
            *((size_t *)current_block + 1) += (HEADER_SIZE + *((size_t *)next_block + 1));
            *((void **)current_block) = *((void **)next_block);
        }

        previous_block = current_block;
        current_block = *((void **)current_block);
    }
}

void own_free(void *ptr)
{
    if (ptr == NULL)
        return;

    void *header_point = (char *)ptr - HEADER_SIZE;
    size_t block_size = *((size_t *)header_point + 1);

    // Beszúrás a lista elejére
    if (header_point < free_blocks)
    {
        *((void **)header_point) = free_blocks;
        free_blocks = header_point;
        own_defragment();
    }
    else
    {
        void *current_block = free_blocks;
        void *previous_block = NULL;

        // Szabad blokkok közötti beszúrás
        while (current_block != NULL && current_block < header_point)
        {
            previous_block = current_block;
            current_block = *((void **)current_block);
        }

        // Beszúrás a két blokk közé
        *((void **)header_point) = current_block;
        if (previous_block != NULL)
        {
            *((void **)previous_block) = header_point;
        }
        else
        {
            free_blocks = header_point;
        }

        // Defragmentálás
        void *merged_block = header_point;
        while (merged_block != NULL)
        {
            void *next_block = *((void **)merged_block);

            if (next_block != NULL && areBorderingBlocks(merged_block, next_block))
            {
                *((size_t *)merged_block + 1) += (HEADER_SIZE + *((size_t *)next_block + 1));
                *((void **)merged_block) = *((void **)next_block);
            }
            else
            {
                break;
            }

            merged_block = *((void **)merged_block);
        }
        own_defragment();
    }
}




//----------------------------Teszteléshez szükséges függvények-----------------------------

#define MEMORY_SIZE 300

// Segédfüggvény a blokkok állapotának kiírásához
void print_memory_state()
{
    printf("Memory state:\n");
    void *current_block = free_blocks;
    while (current_block != NULL)
    {
        size_t block_size = *((size_t *)current_block + 1);
        printf("Free block at address %p, size: %lu\n", current_block, block_size);
        current_block = *((void **)current_block);
    }
}

// Tesztfüggvény az egyes esetek teszteléséhez
void run_tests()
{
    printf("\nInitial memory state:\n");
    print_memory_state();

    // Teszt #1: Alap teszt, különböző méretű blokkok foglalása
    void *a = own_malloc(30);
    printf("\nAfter allocating 'a':\n");
    print_memory_state();
    void *b = own_malloc(40);
    printf("\nAfter allocating 'b':\n");
    print_memory_state();
    void *c = own_malloc(20);
    printf("\nAfter allocating 'c':\n");
    print_memory_state();
    // Teszt #2: Felszabadítás és új foglalás
    own_free(a);
    printf("\nAfter freeing 'a':\n");
    print_memory_state();
    void *d = own_malloc(15);
    printf("\nAfter allocating 'd':\n");
    print_memory_state();
    // Teszt #3: Blokkok összevonása
    own_free(b);
    own_free(c);
    printf("\nAfter freeing 'b' and 'c':\n");
    print_memory_state();
    void *e = own_malloc(80);
    printf("\nAfter allocating 'e':\n");
    print_memory_state();
    // Teszt #4: Blokkok újraösszevonása
    own_free(d);
    printf("\nAfter freeing 'd':\n");
    print_memory_state();
    void *f = own_malloc(70);
    printf("\nAfter allocating 'f':\n");
    print_memory_state();
    // Teszt #5: Teljes memória felszabadítása
    own_free(e);
    own_free(f);
    printf("\nAfter freeing 'e' and 'f':\n");
    print_memory_state();
}

int main(void)
{
    // Az első memória blokk inicializálása
    char memory_arena[MEMORY_SIZE];
    printf("Memory arena starts at address %p\n", memory_arena);
    *(void **)memory_arena = NULL;
    *(size_t *)(memory_arena + sizeof(void *)) = MEMORY_SIZE - HEADER_SIZE;
    free_blocks = memory_arena;
    memory_arena_start = memory_arena;
    run_tests();
    return 0;
}