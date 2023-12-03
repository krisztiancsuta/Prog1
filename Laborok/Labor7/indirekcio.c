void cube(double a, double *area, double *volume)
{
    *volume = a * a * a;
    *area = 6 * a * a;
}

int main()
{
    double sidelength = 3.5;

    // memoriafoglalas az eredmenynek
    double area;
    double volume;

    cube(sidelength, &area, &volume);

    return 0;
}