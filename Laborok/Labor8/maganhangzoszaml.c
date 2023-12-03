int count_vowels(char str[])
{
    int cnt = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (is_vowel(str[i]))
            cnt++;
    }
    return cnt;
}