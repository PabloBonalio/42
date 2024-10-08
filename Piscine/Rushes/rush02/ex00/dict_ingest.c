/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_ingest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:36:14 by pperez-a          #+#    #+#             */
/*   Updated: 2024/06/09 21:37:50 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void		ft_number_sort(char *char_number, int number_len, char *buffer,
				int i);

int	iterate_buffer(char *buffer, uint64_t buffer_size, int number_len,
		char *argv)
{
	uint64_t	i;

	i = 0;
	while (i < buffer_size - 1)
	{
		if (buffer[i] == '\0')
		{
			ft_number_sort(argv, number_len, buffer, 0);
			return (1);
		}
		i++;
	}
	return (0);
}
//should we free(buffer) after sending to number sort? on program gives error
//checked, it is closed in line 83 after success of this function

char	*allocate_and_read_buffer(char *filename, uint64_t buffer_size)
{
	char	*buffer;
	int		fd;
	int64_t	bytes_read;

	buffer = (char *)malloc(buffer_size * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (NULL);
	}
	bytes_read = read(fd, buffer, buffer_size - 1);
	close(fd);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

void	ft_realloc(uint64_t increase, int number_len, char *argv)
{
	char		*buffer;
	uint64_t	buffer_size;

	buffer_size = increase;
	buffer = allocate_and_read_buffer("numbers.dict", buffer_size);
	if (buffer == NULL)
		return ;
	if (iterate_buffer(buffer, buffer_size, number_len, argv) == 0)
	{
		free(buffer);
		ft_realloc(increase + 1, number_len, argv);
	}
	else
		free(buffer);
}
