/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uaupetit <uaupetit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:23:46 by uaupetit          #+#    #+#             */
/*   Updated: 2024/02/19 12:29:02 by uaupetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int i, int fd)
{
	int	nbchar;

	nbchar = 0;
	if (i == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (i < 0)
	{
		nbchar += ft_putchar_fd('-', 1);
		nbchar += ft_putnbr_fd(-i, fd);
	}
	else if (i >= 0 && i <= 9)
		nbchar += ft_putchar_fd((48 + i), fd);
	else
	{
		nbchar += ft_putnbr_fd(i / 10, fd);
		nbchar += ft_putnbr_fd(i % 10, fd);
	}
	return (nbchar);
}
