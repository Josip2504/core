#include <stdio.h>

void ft_printer(int x, int y, int i, int j)
{
	if ((i == 0 && j == 0) || (j == 0 && i == x - 1)
		|| (i == 0 && j == y - 1) || (j == y - 1 && i == x - 1))
		printf("o");
	else if (j == 0 || j == y - 1)
		printf("-");
	else if (i == 0 || i == x - 1)
		printf("|");
	else
		printf(" ");
}

void ft_check(int x, int y)
{
	int i;
	int j;

	j = 0;
	if (x < 0 || y < 0)
		printf("Please enter positive integers.");
	while (j < y)
	{
		i = 0;
		while (i <= x)
		{
			if (i == x)
				printf("\n");
			else
				ft_printer(x, y, i, j);
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
	printf("------------------------------\n");
	ft_check(row, col);
	return (0);
}