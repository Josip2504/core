#include <stdio.h>

int main()
{
	int row;
	int col;

	printf("Enter row number: \n");
	while (scanf("%d", &row) != 1)
	{
		printf("Please enter an integer! \n");
		while (getchar() != '\n');
		printf("Enter row number: \n");
	}
	printf("Enter col number: \n");
	while (scanf("%d", &col) != 1)
	{
		printf("Please enter an integer!\n");
		while (getchar() != '\n');
		printf("Enter col number: \n");
	}
	printf("%d\n", row);
	printf("%d\n", col);
	return (0);
}