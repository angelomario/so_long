/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:37:50 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/29 17:38:07 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	ft_quit_default(int error_type)
{
	if (error_type >= 0)
	{
		ft_putstr("Error\n");
		if (error_type == 0)
			ft_putstr("Invalid name file\n");
		else if (error_type == 1)
			ft_putstr("Invalid map\n");
		else if (error_type == 2)
			ft_putstr("Error to read file\n");
		else if (error_type == 3)
			ft_putstr("Invalid game's variables\n");
		else if (error_type == 4)
			ft_putstr("Some game variable(s) have their way blocked\n");
		else if (error_type == 5)
			ft_putstr("Map too large\n");
		exit (0);
	}
}

int	is_valid_file(char *str, char *param)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i + 4])
		i++;
	if (str[i - 1] == '/' || i == 0)
		return (0);
	while ((str[i] == param[j]) && param[j])
	{
		i++;
		j++;
	}
	return (str[i] == '\0');
}
