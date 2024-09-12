/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 15:47:25 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/29 15:53:50 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_matriz(char **mat)
{
	int	i;

	i = 0;
	if (mat == NULL || *mat == NULL)
	{
		free(mat);
		return ;
	}
	while (mat[i] != NULL)
		free(mat[i++]);
	free(mat);
}

int	ft_quick_game(t_vars *vars)
{
	end_game(*vars, get_start_var(vars->map, 'P'));
	return (0);
}

void	delete_image(t_vars vars)
{
	free(vars.direction);
	free(vars.rogue_see);
	fee_animate(vars);
	delete_run(vars);
	delete_death(vars);
	delete_standing(vars);
	delete_up(vars);
	delete_world(vars);
}

void	clear_window(t_vars vars)
{
	if (vars.mlx != NULL && vars.window != NULL)
	{
		mlx_clear_window(vars.mlx, vars.window);
		mlx_destroy_window(vars.mlx, vars.window);
	}
}

void	end_game(t_vars vars, t_point position)
{
	int	x;
	int	y;

	y = -1;
	while (vars.map[++y] != NULL)
	{
		x = -1;
		while (vars.map[y][++x])
		{
			if (vars.map[y][x] == '0' || vars.map[y][x] == 'C'
					|| vars.map[y][x] == 'E' )
			{
				position = (t_point){x, y};
				showimage('1', vars, position);
			}
		}
	}
	free(vars.enemies);
	delete_image(vars);
	clear_window(vars);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	free(vars.status);
	free_matriz(vars.map);
	exit(0);
}
