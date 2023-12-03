void minmax(double array[], int meret, double *max, double *min)
{
    double kicsi = array[0];
    double nagy = array[0];
    for (int i = 1; i < meret; i++)
    {
        if (array[i] > nagy)
        {
            nagy = array[i];

        }
        if (array[i] < kicsi)
        {
            kicsi = array[i];
        }
    }
    *max = nagy;
    *min = kicsi;
}