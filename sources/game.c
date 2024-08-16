/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 13:10:00 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/14 13:10:44 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game(char **map)
{
	t_vars	vars;
	t_map	map_orig;

	map_orig.map = map;
	if (!map)
		ft_quit_default(1);
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, ft_countstr(map[0]) * 40,
			ft_countline(map) * 40, "so_long");
	map_orig.vars = vars;
	set_path(&map_orig.vars.pictures);
	create_image(&map_orig.vars.pictures, vars);
	showmap(map, map_orig.vars);
	mlx_hook(vars.window, 2, 1L << 0, move, &map_orig);
	mlx_hook(vars.window, 17, 1L << 0, ft_quick_game, &map_orig);
	mlx_loop(vars.mlx);
}
