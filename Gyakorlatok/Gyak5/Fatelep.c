#include <stdio.h>

int main()
{
	double hossz[10], selejt[10] = {0.0};
	int i;
	double d;

	for (i = 0; i < 10; i = i + 1)
		hossz[i] = 8.0;

	while (scanf("%lf", &d) == 1)
	{
		int idx;
		int talalt = 0;
		for (i = 0; i < 10; i++)
		{
			if (hossz[i] < d)
				continue;
			if (!talalt || hossz[i] < hossz[idx])
				idx = i;
			talalt = 1;
		}
		if (talalt)
			hossz[idx] -= d;
		else
		{
			idx = 0;
			for (i = 1; i < 10; i++)
				if (hossz[i] < hossz[idx])
					idx = i;
			selejt[idx] += hossz[idx]; // Figyelem, itt += operátort használunk, hogy összegezze az összes selejtet!
			hossz[idx] = 8.0 - d;
		}
	}

	// Kiíratás
	for (i = 0; i < 10; i++)
		printf("Gep %d: %.2lf m selejt\n", i+1, selejt[i]);

	return 0;
}