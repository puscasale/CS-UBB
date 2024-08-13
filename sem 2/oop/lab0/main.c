#include <stdio.h>

int main()
{
    int n, suma = 0;
    printf("%s", "Introduceti n:");
    scanf("%d", &n);
    int i, nr;
    printf("%s", "Introduceti numerele: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nr);
        suma += nr;
    }
    printf("%s", "Suma numerelor este: ");
    printf("%d", suma);
    return 0;

}