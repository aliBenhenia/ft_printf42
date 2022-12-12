/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:19:13 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/14 16:19:17 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_ptr(unsigned long n)
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

static void	putptr(unsigned long n)
{
	if (n >= 16)
	{
		putptr(n / 16);
		putptr(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			ft_putchar(n + 48);
		}
		else
		{
			ft_putchar(n - 10 + 97);
		}
	}
}

int	printptr(unsigned long n)
{
	write(1, "0x", 2);
	if (n == 0)
	{
		return (2 + write(1, "0", 1));
	}
	putptr(n);
	return (len_ptr(n) + 2);
}
