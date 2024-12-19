#include "libft/libft.h"
#include "minilibx-linux/mlx.h"
#include "minilibx-linux/mlx_int.h"
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void	available_players(void)
{
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir("./assets/textures/players");
	if (!dir)
		return ;
	while ((entry = readdir(dir)) != NULL)
		if (entry->d_name[0] != '.')
			printf("%s\n", entry->d_name);
	closedir(dir);
}

int	main(void)
{
	available_players();
	return (0);
}
