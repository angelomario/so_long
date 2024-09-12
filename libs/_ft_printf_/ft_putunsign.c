/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 09:27:11 by aquissan          #+#    #+#             */
/*   Updated: 2024/05/25 09:30:16 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_length_num(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_length_num(n);
	num = (char *)malloc((len + 1));
	if (!num)
		return (NULL);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_putunsign(unsigned int nbr)
{
	int		len;
	char	*num;

	len = 0;
	if (nbr == 0)
		len += write (1, "0", 1);
	else
	{
		num = ft_utoa(nbr);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}
