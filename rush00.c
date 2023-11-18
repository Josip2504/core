#include <stdio.h>

void ft_check(x, y)
{
	int i = 0;
	int j = 0;

	while (j < y)
	{
		while (i < x)
		{
			printf("o");
			i++;
		}
		j++;
	}
}

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
	ft_check(row, col);
	return (0);
}