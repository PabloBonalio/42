/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:59:30 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/12 18:07:13 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct
{
	int		col;
	int		row;
	char	empty_char;
	char	obstacle_char;
	char	fill_char;
}	Matrixinstr;

int	ft_read_problem(char buffer[MAX_SIZE])
{
	int		my_file;
	ssize_t	bytes_read;
	ssize_t	total_bytes_read;

	total_bytes_read = 0;
	my_file = open("example_file", O_RDONLY);
	if (my_file == -1)
	{
		return (-1);
	}
	bytes_read = read(my_file, buffer + total_bytes_read, MAX_SIZE
				- total_bytes_read - 1);
	if (bytes_read > 0)
		total_bytes_read += bytes_read;
	if (bytes_read == -1)
	{
		close(my_file);
		return (-1);
	}
	buffer[total_bytes_read] = '\0';
	close(my_file);
	return (total_bytes_read);
}

void	load_instr(char buffer[MAX_SIZE], Matrixinstr *instr)
{
	char	*ptr;
	ptr = buffer;
	instr->row = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		instr->row = instr->row * 10 + (*ptr - '0');
		ptr++;
	}
	instr->empty_char = *ptr++;
	instr->obstacle_char = *ptr++;
	instr->fill_char = *ptr++;
	ptr++;
	instr->col = 0;
	while (*ptr != '\n')
	{
		instr->col++;
		ptr++;
	}
	printf("Empty char: %c\nObstacle char: %c\nFill char: %c\n", instr->empty_char, instr->obstacle_char, instr->fill_char);
	printf("col: %i\nrow: %i\n", instr->col, instr->row);
}

char	**empty_matrix(Matrixinstr *instr)
{
	int i;
	int j;
	char** array = (char**)malloc(instr->row * sizeof(char*));

	i = 0;
	while(i < instr->row)
	{
		array[i] = (char *)malloc(instr->col * sizeof(char));
		if (array[i] == NULL)
		{
			j = 0;
			while(j < i)
			{
				free(array[j]);
				j++;
			}
			free(array);
		}
		i++;
	}
	return (array);
}

char	**load_matrix(char *buffer, char **matrix, Matrixinstr *instr)
{
	char	*ptr;
	int		x;
	int		y;
	
	ptr = buffer;
	while (*ptr != '\n')
		ptr++;
	ptr++;
	x = 0;
	while (x < instr->row)
	{
		y = 0;
		while (y < instr->col)
		{
			if (*ptr == instr->obstacle_char)
				matrix[x][y] = instr->obstacle_char;
			else
				matrix[x][y] = instr->empty_char;
			ptr++;
			y++;
		}
		if (*ptr == '\n')
			ptr++;
		x++;
	}
	return (matrix);
}

void	print_matrix(char **matrix, Matrixinstr *instr)
{
	char	output_buffer[MAX_SIZE * MAX_SIZE + MAX_SIZE];
	int		pos;
	int		i;
	int		j;

	pos = 0;
	i = 0;
	while (i < instr->row)
	{
		j = 0;
		while (j < instr->col)
		{
			(output_buffer[pos++] = matrix[i][j]);
			j++;
		}
		output_buffer[pos++] = '\n';
		i++;
	}
	write(1, output_buffer, pos);
}

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

	y = 14;
	while (y >= 0)
	{
		x = 8;
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

int	main(void)
{
	char		**matrix;
	char		buffer[MAX_SIZE];
	Matrixinstr	instr;

	if (ft_read_problem(buffer) == -1)
	{
		perror("Error reading file");
		return (1);
	}
	load_instr(buffer, &instr);
	matrix = load_matrix(buffer, empty_matrix( &instr), &instr);
	print_matrix(matrix, &instr);
	indexes_solutions(matrix, &instr);
	write(1, "\n", 1);
	print_matrix(matrix, &instr);
	return (0);
}
