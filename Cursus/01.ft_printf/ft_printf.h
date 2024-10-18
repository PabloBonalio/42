/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pperez-a <pperez-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:23:10 by pperez-a          #+#    #+#             */
/*   Updated: 2024/10/18 18:41:09 by pperez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar_count(char c, int fd);
int	ft_putstr_count(char *s, int fd);
int	ft_putnbr_count(long long int n, int fd);
int	ft_putnbr_hex_count(unsigned long long n, int fd, int upcase);
int	ft_printf(char const *s, ...);
int	ft_putaddress_count(void *ptr);

#endif
