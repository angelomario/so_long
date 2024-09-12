/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_world.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:31:44 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/20 09:32:08 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_world	set_world(t_vars vars)
{
	t_world	w;

	w.food.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/world/food.xpm",
			&w.food.width, &w.food.height);
	w.wall.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/world/wall.xpm",
			&w.wall.width, &w.wall.height);
	w.floor.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/world/floor.xpm",
			&w.floor.width, &w.floor.height);
	w.box_close.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/world/box_close.xpm", &w.box_close.width,
			&w.box_close.height);
	w.box_open.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/world/box_open.xpm", &w.box_open.width,
			&w.box_open.height);
	w.box_empty.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/world/box_empty.xpm", &w.box_empty.width,
			&w.box_empty.height);
	w.door_open.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/world/door_open.xpm", &w.door_open.width,
			&w.door_open.height);
	w.door_close.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/world/door_1.xpm", &w.door_close.width,
			&w.door_close.height);
	return (w);
}

t_death	set_rogue_death_l(t_vars vars)
{
	t_death	death;

	death.img_1.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dl/1.xpm",
			&death.img_1.width, &death.img_1.height);
	death.img_2.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dl/2.xpm",
			&death.img_2.width, &death.img_2.height);
	death.img_3.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dl/3.xpm",
			&death.img_3.width, &death.img_3.height);
	death.img_4.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dl/4.xpm",
			&death.img_4.width, &death.img_4.height);
	death.img_5.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dl/5.xpm",
			&death.img_5.width, &death.img_5.height);
	return (death);
}

t_death	set_rogue_death_r(t_vars vars)
{
	t_death	death;

	death.img_1.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dr/1.xpm",
			&death.img_1.width, &death.img_1.height);
	death.img_2.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dr/2.xpm",
			&death.img_2.width, &death.img_2.height);
	death.img_3.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dr/3.xpm",
			&death.img_3.width, &death.img_3.height);
	death.img_4.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dr/4.xpm",
			&death.img_4.width, &death.img_4.height);
	death.img_5.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/dr/5.xpm",
			&death.img_5.width, &death.img_5.height);
	return (death);
}
