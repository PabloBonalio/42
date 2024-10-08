/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:45:48 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/12 17:35:59 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct
{
	int		col;
	int		row;
	char	empty_char;
	char	obstacle_char;
	char	fill_char;
}			Matrixinstr;

int	min(char a, char b, char c)
{
	int	min;

	min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return (min);
}

void	indexes_solutions(char **matrix, Matrixinstr *instr)
{
	int	x;
	int	y;

	y = instr->row - 1;
	while (y >= 0)
	{
		x = instr->col - 1;
		while (x >= 0)
		{
			if (matrix[x][y] == instr->obstacle_char)
				matrix[x][y] = '0';
			else if ((x == instr->col - 1 || y == instr->row - 1)
				&& matrix[x][y] != instr->obstacle_char)
				matrix[x][y] = '1';
			else if (matrix[x][y] != instr->obstacle_char)
				matrix[x][y] = min(matrix[x + 1][y], matrix[x][y + 1],matrix[x + 1][y + 1]) + 1;
			x--;
		}
		y--;
	}
}

void	print_solutions(char matrix[MAX_SIZE][MAX_SIZE], Matrixinstr *instr)
{
	char	output_buffer[MAX_SIZE * MAX_SIZE + MAX_SIZE];
	int		pos;
	int		x;
	int		y;

	pos = 0;
	y = 0;
	while (y < instr->row)
	{
		x = 0;
		while (x < instr->col)
		{
			if (matrix[x][y] == 1)
				output_buffer[pos++] = matrix[x][y];
			else if (matrix[x][y] > 1)
				output_buffer[pos++] = matrix[x][y];
			else
				output_buffer[pos++] = matrix[x][y];
			x++;
		}
		output_buffer[pos++] = '\n';
		y++;
	}
	write(STDOUT_FILENO, output_buffer, pos);
}
