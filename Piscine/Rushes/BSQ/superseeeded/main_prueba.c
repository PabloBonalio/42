#include <unistd.h>

void	BSQ(int matrix[][]);

void	ft_putnbr(int nb)
{
	char	digit;

	if (nb == -2147483648)
		write(1, "-2147483648", 12);
	if (nb > -2147483648 && nb <= 2147483647)
	{
		if (nb < 0)
		{
			nb = nb * -1;
			write(1, "-", 1);
		}
		if (nb >= 10)
			ft_putnbr(nb / 10);
		digit = nb % 10 + '0';
		write(1, &digit, 1);
	}
}

void	matrix_init(int matrix[size_x][size_y])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size_y)
	{
		j = 0;
		while (j < size_y)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_matrix(int matrix[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putnbr(matrix[i][j]);
			write(1, " ", 1);
			if (j == SIZE - 1)
			{
				write(1, "\n", 1);
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int	matrix[SIZE][SIZE];


	matrix_init(matrix);
	write(1, "Matriz inicializada a 0\n\n", 25);
	// printeamos estado
	print_matrix(matrix);
	BSQ(matrix);
	write(1, "Matriz con calculos\n\n", 22);
	print_matrix(matrix);
}
