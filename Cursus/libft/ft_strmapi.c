#include <stdlib.h>
#include <string.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *aux_str;
	unsigned int i;
	size_t len;

	if (!s || !f)
		return NULL;

	len = ft_strlen(s);
	aux_str = (char *)malloc(len + 1);
	if (!aux_str)
		return NULL;

	i = 0;
	while (i < len)
	{
		aux_str[i] = f(i, s[i]);
		i++;
	};

	aux_str[len] = 0;
	return aux_str;
}