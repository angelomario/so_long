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

#include "so_long.h"

void	free_matriz(char **mat)
{
	int	i;

	i = 0;
	if (mat == NULL || *mat == NULL)
	{
		free(mat);
		return ;
	}
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

int	ft_quick_game(t_map *map)
{
	end_game(map, get_start_var(map->map, 'P'));
	return (0);
}

void	delete_image(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_left.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_right.img);
	mlx_destroy_image(vars.mlx, vars.pictures.floor_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.food.img);
	mlx_destroy_image(vars.mlx, vars.pictures.door_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.door_open.img);
	mlx_destroy_image(vars.mlx, vars.pictures.wall_1.img);
}

void	clear_window(t_vars vars)
{
	if (vars.mlx != NULL && vars.window != NULL)
	{
		mlx_clear_window(vars.mlx, vars.window);
		mlx_destroy_window(vars.mlx, vars.window);
	}
}

void	end_game(t_map *map, t_point position)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '0' || map->map[y][x] == 'C'
					|| map->map[y][x] == 'E' )
			{
				position = (t_point){x, y};
				showimage('1', map->vars, position, map->vars.pictures);
			}
			x++;
		}
		y++;
	}
	delete_image(map->vars);
	clear_window(map->vars);
	mlx_destroy_display(map->vars.mlx);
	free(map->vars.mlx);
	free_matriz(map->map);
	exit(0);
}
