



int count_generic(char *str, int (*fvptr)(char)){
    int cnt = 0;
    for(int i = 0; str[i] != '\0'; i++){
        if(fvptr(str[i]) == 1){
            cnt++;
        }
    }

    return cnt;

}