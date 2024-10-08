/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:27:37 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/12 16:51:11 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct
{
	int		col;
	int		row;
	char	empty_char;
	char	obstacle_char;
	char	fill_char;
}			MatrixInfo;

void	indexes_solutions(char matrix[MAX_SIZE][MAX_SIZE], MatrixInfo *info);
void	print_solutions(char matrix[MAX_SIZE][MAX_SIZE], MatrixInfo *info);

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
	while ((bytes_read = read(my_file, buffer + total_bytes_read, MAX_SIZE
				- total_bytes_read - 1)) > 0)
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


MatrixInfo	*matrix_info(char buffer[MAX_SIZE])
{
	ptr = buffer;
	MatrixInfo* p = (MatrixInfo*)malloc(sizeof(MatrixInfo));
	if (p == NULL)
		return (1):
	p->row = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		[info]->row = info->row * 10 + (*ptr - '0');
		ptr++;
	}
	info->empty_char = *ptr++;
	info->obstacle_char = *ptr++;
	info->fill_char = *ptr++;
	ptr++;
	info->col = 0;
	while (*ptr != '\n')
	{
		info->col++;
		ptr++;
	}
	ptr -= info->col;
	printf("Empty char: %c\nObstacle char: %c\nFill char: %c\n", info->empty_char, info->obstacle_char, info->fill_char);
	printf("col: %i\nrow: %i\n", info->col, info->row);
};


char	**create_matrix(char buffer[MAX_SIZE], MatrixInfo *info)
{
	char	matrix[MAX_SIZE][MAX_SIZE];
	int		i;
	int		j;
	
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			if (*ptr == info->obstacle_char)
				matrix[i][j] = info->obstacle_char;
			else
				matrix[i][j] = info->empty_char;
			ptr++;
			j++;
		}
		if (*ptr == '\n')
			ptr++;
		i++;
	}
}

void	load_matrix(char buffer[MAX_SIZE], char matrix[MAX_SIZE][MAX_SIZE],
		MatrixInfo *info)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = buffer;
	info->row = 0;
	while (*ptr >= '0' && *ptr <= '9')
	{
		info->row = info->row * 10 + (*ptr - '0');
		ptr++;
	}
	info->empty_char = *ptr++;
	info->obstacle_char = *ptr++;
	info->fill_char = *ptr++;
	ptr++;
	info->col = 0;
	while (*ptr != '\n')
	{
		info->col++;
		ptr++;
	}
	ptr -= info->col;
	printf("Empty char: %c\nObstacle char: %c\nFill char: %c\n", info->empty_char, info->obstacle_char, info->fill_char);
	printf("col: %i\nrow: %i\n", info->col, info->row);
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{
			if (*ptr == info->obstacle_char)
				matrix[i][j] = info->obstacle_char;
			else
				matrix[i][j] = info->empty_char;
			ptr++;
			j++;
		}
		if (*ptr == '\n')
			ptr++;
		i++;
	}
}

void	print_matrix(char matrix[MAX_SIZE][MAX_SIZE], MatrixInfo *info)
{
	char	output_buffer[MAX_SIZE * MAX_SIZE + MAX_SIZE];
	int		pos;
	int		i;
	int		j;

	pos = 0;
	i = 0;
	while (i < info->row)
	{
		j = 0;
		while (j < info->col)
		{ 
			if (matrix[i][j] == info->obstacle_char)
				output_buffer[pos++] = info->obstacle_char;
			else
				output_buffer[pos++] = info->empty_char;
			j++;
		}
		output_buffer[pos++] = '\n';
		i++;
	}
	write(STDOUT_FILENO, output_buffer, pos);
}

int	main(void)
{
	char		buffer[MAX_SIZE];
	char		matrix[MAX_SIZE][MAX_SIZE];
	MatrixInfo	info;

	if (ft_read_problem(buffer) == -1)
	{
		perror("Error reading file");
		return (1);
	}
	load_matrix(buffer, matrix, &info);
	printf("Matriz original:\n");
	print_matrix(matrix, &info);
	indexes_solutions(matrix, &info);
	printf("\nMatriz procesada:\n");
	print_solutions(matrix, &info);
	//print_matrix(matrix, &info);
	return (0);
}
