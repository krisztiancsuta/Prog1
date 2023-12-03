unsigned int str_to_num(char *num, unsigned int numsystem){
     unsigned int res = 0;
     for (int i = 0; num[i] != '\0'; i++)
     {
     
        res = res * numsystem + (num[i]-'0');
     }
     
     return res;
}