void seven_to_zero(int t[], int meret)
{
    for (int i = 0; i < meret; i++)
    {
        if (t[i] % 7 == 0)
            t[i] = 0;
    }
}