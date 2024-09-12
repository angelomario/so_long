/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:24:27 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/26 09:25:46 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	rm_direction(char *direction)
{
	int	i;

	i = 0;
	while (direction[i + 1] != '\0')
	{
		direction[i] = direction[i + 1];
		i++;
	}
	direction[i] = '\0';
}

char	*reset_direction(int i)
{
	char	*str;
	int		j;

	j = 0;
	str = (char *)malloc(sizeof(char) * i);
	while (j < i)
		str[j++] = '\0';
	return (str);
}

int	get_direction_p(t_vars vars, char personal, t_point position)
{
	int	half;

	half = ft_countstr(vars.map[0]) / 2;
	if (position.x <= half)
	{
		if (personal == 'P')
			return (1);
		return (3);
	}
	if (personal == 'P')
		return (0);
	return (2);
}

void	set_direction(t_vars vars, char direction)
{
	int	i;

	i = 0;
	while (vars.direction[i + 1])
	{
		vars.direction[i] = vars.direction[i + 1];
		i++;
	}
	if (i < 3)
		vars.direction[i] = direction;
	else if (i == 3)
	{
		vars.direction[i - 1] = direction;
		vars.direction[4] = '\0';
	}
}
