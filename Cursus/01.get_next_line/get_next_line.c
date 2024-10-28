/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:40:18 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/28 16:38:50 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_file(char *doc, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	char	*new_doc;
	int		read_result;

	read_result = 1;
	while (read_result > 0)
	{
		read_result = read(fd, tmp, BUFFER_SIZE);
		if (read_result == -1)
			return ;
		tmp[read_result] = 0;
		new_doc = ft_strjoin(*doc, tmp);
		free(*doc);
		*doc = new_doc;
		if (*doc == NULL)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*doc = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	copy_file(doc, fd);
	return (line);
}
