/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:08:01 by abenheni          #+#    #+#             */
/*   Updated: 2022/11/14 16:08:04 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdarg.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>

int		ft_printf(const char *f, ...);
int		printnbr(int n);
int		printstr(char *s);
int		printpercent(void);
int		printhex(unsigned int n, char f);
int		printunsigned(unsigned int n);
int		printptr(unsigned long n);
void	ft_putchar(char c);
void	ft_putstr(char *s);
size_t	ft_strlen(const char *s);
#endif
