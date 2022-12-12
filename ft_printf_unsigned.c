/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:22:28 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/14 16:22:30 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	lenunsigned(unsigned int n)
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

static void	ft_putnbr(unsigned int n)
{
	if (n <= 9)
		ft_putchar(n + 48);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	printunsigned(unsigned int n)
{
	if (n == 0)
		return (write(1, "0", 1));
	ft_putnbr(n);
	return (lenunsigned(n));
}
