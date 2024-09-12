/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:24:38 by aquissan          #+#    #+#             */
/*   Updated: 2024/05/24 17:25:39 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_params(char const ch, int *len, va_list list)
{
	if (ch == 'd' || ch == 'i')
		(*len) += ft_putnbr(__builtin_va_arg(list, int));
	else if (ch == 's')
		(*len) += ft_putstr(__builtin_va_arg(list, char *));
	else if (ch == 'x' || ch == 'X')
		(*len) += ft_puthex(__builtin_va_arg(list, unsigned int), ch);
	else if (ch == 'p')
		(*len) += (ft_putptr(__builtin_va_arg(list, unsigned long long)));
	else if (ch == 'u')
		(*len) += ft_putunsign((__builtin_va_arg(list, unsigned int)));
	else if (ch == 'c')
		(*len) += ft_putchar((char)__builtin_va_arg(list, int));
	else if (ch == '%')
		(*len) += ft_putchar(ch);
}

int	ft_integer(char const ch, int *len, va_list *list, int *count)
{
	int	num;

	num = (int)__builtin_va_arg((*list), int);
	if ((ch == '+' || ch == ' ') && (num >= 0))
	{
		(*len) += ft_putchar(ch);
		(*len) += ft_putnbr(num);
		(*count) += 2;
	}
	else if (ch == '-')
	{
		(*len) += ft_putnbr(num);
		(*count) += 2;
	}
	else if ((ch == '+' || ch == ' ') && (num < 0))
	{
		(*len) += ft_putnbr(num);
		(*count) += 2;
	}
	else
	{
		(*len) += ft_putnbr(num);
		(*count) += 1;
	}
	return (*len);
}

int	ft_hexadecimal(va_list *list, char const ch, int *i)
{
	int	num;
	int	len;

	num = __builtin_va_arg((*list), unsigned int);
	len = 0;
	if (num == (unsigned int)0)
	{
		len += ft_putchar('0');
		(*i) += 2;
	}
	else if (num < 0)
	{
		len += ft_putchar('0');
		len += ft_putchar(ch);
		len += ft_puthex(num, ch);
		(*i) += 2;
	}
	else
	{
		len += ft_putchar('0');
		len += ft_putchar(ch);
		len += ft_puthex(num, ch);
		(*i) += 2;
	}
	return (len);
}

int	ft_flags(char const *str, va_list *list, int *i)
{
	int	letter;

	letter = 0;
	if (str[*i] == '%' && str[*i + 1] != '\0')
	{
		if (str[*i + 1] == '#' && (str[*i + 2] == 'x'
				|| str[(*i) + 2] == 'X'))
			letter += ft_hexadecimal(&(*list), str[(*i) + 2], &(*i));
		else if ((str[(*i) + 1] == '+' || str[(*i) + 1] == ' '
				|| str[(*i) + 1] == '-')
			&& (str[(*i) + 2] == 'd' || str[(*i) + 2] == 'i'))
			ft_integer(str[(*i) + 1], &letter, list, &(*i));
		else if ((str[(*i) + 1] == '+' || str[(*i) + 1] == ' ')
			&& str[(*i) + 2] == 's')
			(*i) += 2;
		else
			ft_params(str[++(*i)], &letter, (*list));
	}
	else
		letter += ft_putchar(str[(*i)]);
	return (letter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		letter;

	va_start(list, str);
	i = -1;
	letter = 0;
	while (str[++i])
	{
		letter += ft_flags(str, &list, &i);
	}
	va_end(list);
	return (letter);
}
