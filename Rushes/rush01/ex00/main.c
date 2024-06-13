/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:29:48 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/02 22:08:58 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ROWS 4
#define COLUMNS 4

void	ft_atoi_parse(char *str, int *clues);
void	ft_validate(int *clues);
void	ft_putnbr(int nb);

void	matrix_init(int matrix[ROWS][COLUMNS])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < COLUMNS)
	{
		j = 0;
		while (j < ROWS)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_matrix(int matrix[ROWS][COLUMNS], int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < COLUMNS)
	{
		j = 0;
		while (j < ROWS)
		{
			ft_putnbr(matrix[i][j]);
			write(1, " ", 1);
			if (j == ROWS - 1)
			{
				write(1, "\n", 1);
			}
			j++;
		}
		i++;
	}
}
/*
int	check_top_index(int matrix[ROWS][COLUMNS], int temp, int *i, int *clues)
{
	int	counter;
	int	k;
	int	max_height;
	int	k;

	k = 0;
	max_height = 0;
	counter = 1;
	printf("\nEL VALOR temporal que comprobamos es %d, ", temp);
	// desde j 0 hasta j 4 counter +1 si mayor
	while (k < 4)
	{
		if (matrix[i[0]][k] > max_height)
			max_height = matrix[i[0]][k];
		if (matrix[i[0]][k] < matrix[i[0]][k + 1]
			&& matrix[i[0]][k]< max_height)
			counter++;
		k++;
	}
	printf("comprobamos columna %d con vista %d\n", i[0], clues[i[1]]);
	if (counter > clues[i[1]])
	{
		printf("%d es el counter comparado con %d\n", counter, clues[i[1]]);
		printf("ESTE NUMERO NO VALE");
		return (0);
	}
	return (1);
}*/

int	check_row_column(int matrix[ROWS][COLUMNS], int temp, int i, int j)
{
	int	k;

	k = 0;
	while (k < ROWS)
	{
		if (matrix[i][k] == temp)
			return (0);
		k++;
	}
	k = 0;
	while (k < COLUMNS)
	{
		if (matrix[k][j] == temp)
			return (0);
		k++;
	}
	return (1);
}

void	assign_values(int matrix[ROWS][COLUMNS], int *clues, int temp)
{
	int	xy[2];

	xy[0] = 0;
	while (xy[0] < COLUMNS)
	{
		xy[1] = 0;
		while (xy[1] < ROWS)
		{
			if (matrix[xy[0]][xy[1]] == 0)
			{
				temp = 1;
				while (temp <= 4)
				{
					if (check_row_column(matrix, temp, xy[0], xy[1]) == 1)
					{
						matrix[xy[0]][xy[1]] = temp;
						break ;
						// write(1, "HEMOS LLEGAO\n", 14);
						/*if (check_top_index(matrix, temp, xy[0], clues) == 1)
						{
							matrix[i[0]][i[1]] = temp;
							break ;
						}
						else if((check_top_index(matrix, temp, xy[0],
									clues) == 0))
						{
							matrix[xy[0]][xy[1]] = 0;
							temp++;
							check(matrix, temp, xy[0], xy[1]);
							print_matrix(matrix, clues);
						}*/
					}
					temp++;
				}
			}
			xy[1]++;
		}
		xy[0]++;
	}
}

int	main(int argc, char **argv)
{
	int	matrix[ROWS][COLUMNS];
	int	clues[16];
	int	temp;
	int	i;
	int	j;

	temp = 1;
	i = 0;
	j = 0;
	if (argc != 2)
	{
		write(1, "1error\n", 7);
		return (1);
	}
	ft_atoi_parse(argv[1], clues);
	ft_validate(clues);
	// inicializamos a 0
	matrix_init(matrix);
	write(1, "Matriz inicializada a 0\n", 25);
	// printeamos estado
	print_matrix(matrix, clues);
	// 2 primeros 4 obligatorios
	while (i < 16)
	{
		if (clues[i] == 4)
		{
			if (i <= 3)
			{
				// row up
				matrix[0][i] = 1;
				matrix[1][i] = 2;
				matrix[2][i] = 3;
				matrix[3][i] = 4;
			}
			else if (i >= 4 && i <= 7)
			{
				// row down
				matrix[i - 4][0] = 1;
				matrix[i - 4][1] = 2;
				matrix[i - 4][2] = 3;
				matrix[i - 4][3] = 4;
			}
			else if (i >= 8 && i <= 11)
			{
				// col left
				matrix[i - 8][0] = 1;
				matrix[i - 8][1] = 2;
				matrix[i - 8][2] = 3;
				matrix[i - 8][3] = 4;
			}
			else if (i >= 12 && i <= 15)
			{
				// col right
				matrix[i - 12][0] = 4;
				matrix[i - 12][1] = 3;
				matrix[i - 12][2] = 2;
				matrix[i - 12][3] = 1;
			}
		}
		i++;
	}
	write(1, "\n\n", 3);
	write(1, "Primera comprobación\n", 23);
	print_matrix(matrix, clues);
	assign_values(matrix, clues, temp);
	write(1, "\niteracion de valores posibles\n", 31);
	print_matrix(matrix, clues);
	return (0);
}
