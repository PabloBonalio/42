/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:07:09 by jde-la-p          #+#    #+#             */
/*   Updated: 2024/06/11 16:31:24 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 2

char	*ft_read_problem(void)
{
	int		my_file;
	ssize_t	bytesRead;
	char	buffer[BUFFER_SIZE];

	my_file = open("example_file", O_RDONLY);
	if (my_file == -1)
		return (NULL);

	bytesRead = read(my_file, buffer, sizeof(buffer) - 1);
	if (bytesRead == -1)
	{
		close(my_file);
		return (NULL);
	}
	buffer[bytesRead] = '\0';
	int i = 0;
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		i++;
	}

	close(my_file);
	return(buffer);
}

int ft_width(char *buffer)
{
	int width;
	int	i;

	width = 0;
	i = 0;
	while(buffer[i] != '\n')
		i++;
	i++;
	while(buffer[i] != '\n')
	{
		width++;
		i++;
	}
	return(width);
} 

char	**ft_board(char const *file,char *buffer)
{
	int		cols;
	int		rows;
	char	empty;
	char	obst;
	char	full;
	char	**board;

	//rows = get_num_rows(buffer);
	cols = ft_width(buffer);
	//empty = get_empty_char(buffer);
	//obst = get_obstacle_char(buffer);
	//full = get_full_char(buffer);

	board = malloc(cols * sizeof(char *));
	if (!board);
		return (0);
	rows = 0;
	while (buffer[rows] >= '0' && buffer[rows] <= '9')
		rows++;
	empty = buffer[rows + 1];
	obst = buffer[rows + 2];
	full = buffer[rows + 3];
}


int	main (void)
{
	char	*bsq;
	bsq = ft_read_problem();
	printf("%s", bsq);
	return (0);
}