/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_animations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:16:33 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/18 19:53:51 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_codes.h"
#include "so_long.h"

void	load_player_images(void)
{
	t_list	player;

	player = load_frames_from_folder("./assets/textures/bunny");
}
t_list	load_frames_from_folder(const char *folder_path)
{
	struct dirent	*entry;
	DIR				*dir;
	char			*file_path;
	t_list			*list;

	dir = opendir(folder_path);
	if (!dir)
		error("Unable to open folder", 0, 1);
	while ((entry = readdir(dir)) != NULL)
	{
		if (entry->d_name[0] == '.')
			continue ;
		ft_lstadd_back(&list, ft_lstnew(entry->d_name));
	}
	closedir(dir);
	return (*list);
}
