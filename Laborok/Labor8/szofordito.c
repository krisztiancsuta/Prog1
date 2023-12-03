#include <stdio.h>
#include <string.h>

void reverse_segment(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverse_words(char *str) {
    int length = strlen(str);
    int start = 0;

    for (int i = 0; i <= length; i++) {
        // A szó vége a szóköz helye vagy a sztring vége
        if (str[i] == ' ' || str[i] == '\0') {
            reverse_segment(str, start, i - 1);
            start = i + 1;
        }
    }
}

int main() {
    char str[100];
    printf("Kerem a szoveget: ");
    fgets(str, sizeof(str), stdin);
    
    // Újsor karakter eltávolítása
    size_t length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
    
    reverse_words(str);
    printf("Megforditott szavak: %s\n", str);
    
    return 0;
}
