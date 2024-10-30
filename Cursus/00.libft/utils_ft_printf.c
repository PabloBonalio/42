/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:18:52 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/18 18:43:08 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_count(char *s, int fd)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
	{
		count += ft_putstr_count("(null)", fd);
		return (count);
	}
	while (s[i] != 0)
	{
		count += ft_putchar_count(s[i], fd);
		i++;
	}
	return (count);
}

int	ft_putnbr_count(long long int n, int fd)
{
	unsigned long long	nbr;
	int					count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_count('-', 1);
		nbr = n * -1;
	}
	else
		nbr = n;
	if (nbr >= 10)
		count += ft_putnbr_count(nbr / 10, fd);
	count += ft_putchar_count((nbr % 10) + 48, fd);
	return (count);
}

int	ft_putnbr_hex_count(unsigned long long nbr, int fd, int upcase)
{
	int					count;
	char				*base;

	if (upcase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_putnbr_hex_count(nbr / 16, fd, upcase);
	count += ft_putchar_count(base[nbr % 16], fd);
	return (count);
}

int	ft_putaddress_count(void *ptr)
{
	unsigned long long	address;
	int					count;

	address = (unsigned long long)ptr;
	count = 0;
	if (address == 0)
		count += ft_putstr_count("(nil)", 1);
	else
	{
		count += ft_putstr_count("0x", 1);
		count += ft_putnbr_hex_count(address, 1, 0);
	}
	return (count);
}
