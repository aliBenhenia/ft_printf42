/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:00:26 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/14 16:00:29 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	format(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += printchar(va_arg(arg, int));
	else if (c == 'd' || c == 'i')
		len += printnbr(va_arg(arg, int));
	else if (c == 's')
		len += printstr(va_arg(arg, char *));
	else if (c == '%')
		len += printpercent();
	else if (c == 'X' || c == 'x')
		len += printhex(va_arg(arg, unsigned int), c);
	else if (c == 'u')
		len += printunsigned(va_arg(arg, unsigned int));
	else if (c == 'p')
		len += printptr(va_arg(arg, unsigned long));
	va_end(arg);
	return (len);
}

int	ft_printf(const char *f, ...)
{
	int		len;
	int		i;
	va_list	arg;

	va_start(arg, f);
	i = 0;
	len = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			len = len + format(arg, f[i + 1]);
			i++;
			if (f[i] == '\0')
				break ;
		}
		else
			len += printchar(f[i]);
		i++;
	}
	va_end(arg);
	return (len);
}
