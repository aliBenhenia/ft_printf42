/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:16:56 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/14 16:16:58 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned int n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		counter++;
		n = n / 16;
	}
	return (counter);
}

static void	puthex(unsigned int n, char f)
{
	if (n >= 16)
	{
		puthex(n / 16, f);
		puthex(n % 16, f);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar(n + 48);
		}
		else
		{
			if (f == 'X')
			{
				ft_putchar(n - 10 + 65);
			}
			if (f == 'x')
			{
				ft_putchar(n - 10 + 97);
			}
		}
	}
}

int	printhex(unsigned int n, char f)
{
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	puthex(n, f);
	return (len_hex(n));
}
