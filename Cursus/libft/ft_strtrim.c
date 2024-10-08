#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux_str;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	aux_str = malloc(end - start + 2);
	if (!aux_str)
		return (NULL);
	i = 0;
	while (start <= end)
		aux_str[i++] = s1[start++];
	aux_str[i] = 0;
	return (aux_str);
}