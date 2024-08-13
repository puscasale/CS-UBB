#include <stdio.h>
#include <string.h>

const char* conversie_rapida(const char*);

int main()
{
	int n;
	char line[33];

	printf("Numarul de numere: ");
	scanf_s("%d", &n);
	getchar();

	for(int i = 0; i < n; i ++) 
	{
		printf("Numarul in baza 2: ");
		memset(line, 0, sizeof(line));
		fgets(line, sizeof(line), stdin);
		strtok(line, "\n");
		
		printf("Numarul in baza 8: %s\n\n", conversie_rapida(line));
	}

	return 0;
}