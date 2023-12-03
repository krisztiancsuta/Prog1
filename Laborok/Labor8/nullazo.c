int remove_zeros(int *t, int meret)
{
    int from;
    int to = 0;

    for (from = 0; from < meret; from++)
    {
        if (t[from] != 0)
        {
            t[to] = t[from];
            to++;
        }
    }
    return to;
}
int main()
{
    int t[] = {-2, 1, 0, 2, -3, -3, 1, -3, 0, 3, 2, 0, 3, 2, -1, -1, 0, -1, 1};
    int x = remove_zeros(&t[0], 19);

    return 0;
}