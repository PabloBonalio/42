#include <stdlib.h>

static int	get_num_length(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*aux_str;
	int		len;
	long	num;
	int		sign;

	num = n;
	sign = 0;
	if (n < 0)
	{
		num = -num;
		sign = 1;
	}
	len = get_num_length(n);
	aux_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!aux_str)
		return (NULL);
	aux_str[len] = 0;
	while (len--)
	{
		aux_str[len] = (num % 10) + '0';
		num /= 10;
	}
	if (sign)
		aux_str[0] = '-';
	return (aux_str);
}
