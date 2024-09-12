/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:37:32 by aquissan          #+#    #+#             */
/*   Updated: 2024/05/25 12:37:37 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_printfhex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_printfhex(num / 16, format);
		ft_printfhex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				ft_putchar((num - 10 + 'a'));
			if (format == 'X')
				ft_putchar((num - 10 + 'A'));
		}
	}
}

int	ft_puthex(unsigned int num, const char format)
{
	if (num == 0)
		return (ft_putchar('0'));
	else
		ft_printfhex(num, format);
	return (ft_hexlen(num));
}
