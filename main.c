#include <stdio.h>
#include <stdlib.h>

#define ILOSC_DANYCH 5
#define ILOSC_KOMEND 2

int main(void)
{
    char * komendy[] = {"set title \"Generowanie sygnału\"", "plot 'data.temp'"};
    double x[ILOSC_DANYCH] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[ILOSC_DANYCH] = {5.0, 3.0, 1.0, 3.0, 5.0};

    FILE * temp = fopen("data.temp", "w");

    FILE * gnuplot = popen ("gnuplot -persistent", "w");

    int i;

    for (i = 0; i < ILOSC_DANYCH; i++)
    {
        fprintf(temp, "%lf %lf \n", x[i], y[i]);
    }

    for (i = 0; i < ILOSC_KOMEND; i++)
    {
        fprintf(gnuplot, "%s \n", komendy[i]);
    }

    fflush(gnuplot);

    return 0;
}

