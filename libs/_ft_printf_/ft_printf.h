/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:25:46 by aquissan          #+#    #+#             */
/*   Updated: 2024/05/24 18:07:31 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_error(char *str);
int		ft_convertion(unsigned int num, char *str);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putchar(char ch);
int		ft_putstr(char *str);
int		ft_putunsign(unsigned int n);
int		ft_putptr(unsigned long long ptr);
int		ft_puthex(unsigned int num, const char format);
char	*ft_itoa(int n);

#endif
