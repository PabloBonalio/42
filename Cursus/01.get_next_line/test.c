/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:21 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/30 18:06:26 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
		return (1);
	// Open file for reading and writing, create if it doesn't exist
	fd = open(argv[1], O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (1);
	line = get_next_line(0);
	if (line)
	{
		write(fd, line, ft_strlen_gnl(line));
		free(line);
	}
	close(fd);
	return (0);
}
