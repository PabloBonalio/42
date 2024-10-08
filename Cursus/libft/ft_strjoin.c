#include <stdlib.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	char	*aux_str;
	int		i;
	int		j;

	aux_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!aux_str)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		aux_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		aux_str[i] = s2[j];
		i++;
		j++;
	}
	i++;
	aux_str[i] = 0;
	return (aux_str);
}