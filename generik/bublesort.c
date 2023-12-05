
void swap(void *_a, void *_b, int size){
    char *a = (char *)_a;
    char *b = (char *)_b;//minden pointer 8 byteos
    for(int i = 0; i < size;i++){
        char temp = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = temp;
    }

}

void sort(void *_t, int n, int size_t, int (*cmp)(void *, void *)){

    char *t = (char *)_t;
    for(int i = 0; i < n-1; i++)    
        for(int j = 0; j < n - i - 1; j++)
            if(cmp(t + j*size_t, t + (j + 1)*size_t) > 0)
                swap(t + j*size_t, t + (j + 1)*size_t, size_t);

}

int cmp(void *_a, void *_b){
    int *a = (int *)_a;
    int *b = (int *)_b;
    if(*a > *b)return 1;
    if(*a < *b)return -1;
    return 0;
}

int main(){
    int t[] = {9,8,7,6,2,3,3,4,5,7,7,8,4,3,2,4,5,6,7,4,3,2,4,5,6,4};
    sort(t,26,sizeof(int),cmp);
}