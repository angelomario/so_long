/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:41:45 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/14 12:41:49 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_path(t_pitures *pictures)
{
	pictures->rogue_left.path = "./assets/rogue/rogue_left.xpm";
	pictures->rogue_run_left.path = "./assets/rogue/rogue_run_left.xpm";
	pictures->rogue_run_right.path = "./assets/rogue/rogue_run_right.xpm";
	pictures->rogue_right.path = "./assets/rogue/rogue_right.xpm";
	pictures->rogue_death_c_right.path
		= "./assets/rogue/rogue_death_c_right.xpm";
	pictures->rogue_death_c_left.path = "./assets/rogue/rogue_death_c_left.xpm";
	pictures->rogue_death_left.path = "./assets/rogue/rogue_death_left.xpm";
	pictures->rogue_death_right.path = "./assets/rogue/rogue_death_right.xpm";
	pictures->enemy_left.path = "./assets/enemy/enemy_left.xpm";
	pictures->enemy_right.path = "./assets/enemy/enemy_right.xpm";
	pictures->enemy_run_right.path = "./assets/enemy/enemy_run_right.xpm";
	pictures->enemy_run_left.path = "./assets/enemy/enemy_run_left.xpm";
	pictures->floor_1.path = "./assets/floor/floor_1.xpm";
	pictures->floor_2.path = "./assets/floor/floor_2.xpm";
	pictures->food.path = "./assets/food/food.xpm";
	pictures->trunk_closed.path = "./assets/food/trunk_closed.xpm";
	pictures->trunk_food_open.path = "./assets/food/trunk_food_open.xpm";
	pictures->trunk_open.path = "./assets/food/trunk_open.xpm";
	pictures->door_1.path = "./assets/door/door_1.xpm";
	pictures->door_dark_1.path = "./assets/door/door_dark_1.xpm";
	pictures->door_dark_pl.path = "./assets/door/door_dark_pl.xpm";
	pictures->door_open.path = "./assets/door/door_open.xpm";
	pictures->door_dark_pr.path = "./assets/door/door_dark_pr.xpm";
	pictures->wall_1.path = "./assets/door/wall_1.xpm";
}

void	showimage(char ch, t_vars vars, t_point position, t_pitures pictures)
{
	t_img	image;

	if (ch == '1')
		image = pictures.wall_1;
	else if (ch == '0')
		image = pictures.floor_1;
	else if (ch == 'C')
		image = pictures.food;
	else if (ch == 'E')
		image = pictures.door_1;
	else if (ch == 'P')
		image = pictures.rogue_right;
	else if (ch == 'r')
		image = pictures.rogue_right;
	else if (ch == 'l')
		image = pictures.rogue_left;
	else if (ch == 'e')
		image = pictures.door_open;
	if (!ft_ch_in_str(ch, "10CEPler"))
		return ;
	mlx_put_image_to_window(vars.mlx, vars.window,
		image.img,
		position.x * (image.width),
		position.y * image.height);
}

void	create_image(t_pitures *pictures, t_vars vars)
{
	pictures->rogue_right.img = mlx_xpm_file_to_image(vars.mlx,
			pictures->rogue_right.path, &pictures->rogue_right.width,
			&pictures->rogue_right.height);
	pictures->rogue_left.img = mlx_xpm_file_to_image(vars.mlx,
			pictures->rogue_left.path, &pictures->rogue_left.width,
			&pictures->rogue_left.height);
	pictures->floor_1.img = mlx_xpm_file_to_image(vars.mlx,
			pictures->floor_1.path, &pictures->floor_1.width,
			&pictures->floor_1.height);
	pictures->door_open.img = mlx_xpm_file_to_image(vars.mlx,
			pictures->door_open.path, &pictures->door_open.width,
			&pictures->door_open.height);
	pictures->wall_1.img = mlx_xpm_file_to_image(vars.mlx,
			pictures->wall_1.path, &pictures->wall_1.width,
			&pictures->wall_1.height);
	pictures->door_1.img = mlx_xpm_file_to_image(vars.mlx,
			pictures->door_1.path, &pictures->door_1.width,
			&pictures->door_1.height);
	pictures->food.img = mlx_xpm_file_to_image(vars.mlx, pictures->food.path,
			&pictures->food.width, &pictures->food.height);
}
