/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:29:39 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/29 15:30:12 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wdqtd(char *str, char c)
{
	int	i;
	int	qtd;

	i = 0;
	qtd = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			qtd++;
			i++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (qtd);
}

int	ft_strlen2(char *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	*ft_getwd(char *str, char c, int start)
{
	int			i;
	char		*s;

	i = 0;
	s = (char *)malloc(sizeof(char) * ((ft_strlen2(str, c, start)) + 1));
	if (!s)
		return (NULL);
	while (str[start] != c && str[start])
		s[i++] = str[start++];
	s[i] = '\0';
	return (s);
}

int	is_char(char ch)
{
	if (ch >= 9 && ch <= 13)
		return (0);
	return (1);
}

char	**ft_split(char *str)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	j = 0;
	split = (char **)malloc(sizeof(char *) * (wdqtd(str, '\n') + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n' && is_char(str[i + 1]) == 0)
			return (NULL);
		while ((str[i] == '\n' || str[i] == ' '
				|| str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			split[j++] = ft_getwd(str, '\n', i++);
		while (str[i] != '\n' && str[i] != '\0')
			i++;
	}
	split[j] = NULL;
	return (split);
}
