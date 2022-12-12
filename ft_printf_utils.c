/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:24:16 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/14 16:24:21 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + 48);
	}
}

static int	lennbr(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	printnbr(int n)
{
	int	i;

	if (n == 0)
		return (write(1, "0", 1));
	i = lennbr(n);
	if (n < 0)
		i++;
	ft_putnbr(n);
	return (i);
}

int	printstr(char *s)
{
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(s);
	return ((int)ft_strlen(s));
}

int	printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
