/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:25:10 by pperez-a          #+#    #+#             */
/*   Updated: 2024/12/04 16:27:07 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	what_var(int fd, char chr, va_list arg)
{
	int	count;

	count = 0;
	if (chr == '%')
		count += ft_putchar_count('%', fd);
	else if (chr == 'c')
		count += ft_putchar_count(va_arg(arg, int), fd);
	else if (chr == 's')
		count += ft_putstr_count(va_arg(arg, char *), fd);
	else if (chr == 'd' || chr == 'i')
		count += ft_putnbr_count(va_arg(arg, int), fd);
	else if (chr == 'u')
		count += ft_putnbr_count(va_arg(arg, unsigned int), fd);
	else if (chr == 'x')
		count += ft_putnbr_hex_count(va_arg(arg, unsigned int), fd, 0);
	else if (chr == 'X')
		count += ft_putnbr_hex_count(va_arg(arg, unsigned int), fd, 1);
	else if (chr == 'p')
		count += ft_putaddress_count(va_arg(arg, void *));
	else
		return (-1);
	return (count);
}

int	ft_printf(int fd, char const *s, ...)
{
	va_list	arg;
	int		s_index;
	int		count;
	int		result;

	va_start(arg, s);
	s_index = 0;
	count = 0;
	while (s[s_index])
	{
		if (s[s_index] == '%')
		{
			s_index++;
			if (!s[s_index])
				break ;
			result = what_var(fd, s[s_index], arg);
			if (result == -1)
				return (va_end(arg), -1);
			count += result;
		}
		else
			count += ft_putchar_count(s[s_index], 1);
		s_index++;
	}
	return (va_end(arg), count);
}
