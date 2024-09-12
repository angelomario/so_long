/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_standing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:46:59 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/19 18:48:50 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_standing	set_rogue_standing_right(t_vars vars)
{
	t_standing	rogue;

	rogue.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/r/1.xpm", &rogue.img_1.width,
			&rogue.img_1.height);
	rogue.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/r/2.xpm", &rogue.img_2.width,
			&rogue.img_2.height);
	rogue.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/r/3.xpm",
			&rogue.img_3.width, &rogue.img_3.height);
	rogue.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/r/4.xpm", &rogue.img_4.width, &rogue.img_4.height);
	return (rogue);
}

t_standing	set_rogue_standing_left(t_vars vars)
{
	t_standing	rogue;

	rogue.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/l/1.xpm", &rogue.img_1.width,
			&rogue.img_1.height);
	rogue.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/l/2.xpm", &rogue.img_2.width,
			&rogue.img_2.height);
	rogue.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/l/3.xpm",
			&rogue.img_3.width, &rogue.img_3.height);
	rogue.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/l/4.xpm", &rogue.img_4.width, &rogue.img_4.height);
	return (rogue);
}

t_standing	set_orc_standing_left(t_vars vars)
{
	t_standing	orc;

	orc.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/l/1.xpm", &orc.img_1.width,
			&orc.img_1.height);
	orc.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/l/2.xpm", &orc.img_2.width,
			&orc.img_2.height);
	orc.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/l/3.xpm",
			&orc.img_3.width, &orc.img_3.height);
	orc.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/l/4.xpm", &orc.img_4.width, &orc.img_4.height);
	return (orc);
}

t_standing	set_orc_standing_right(t_vars vars)
{
	t_standing	orc;

	orc.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/r/1.xpm", &orc.img_1.width,
			&orc.img_1.height);
	orc.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/r/2.xpm", &orc.img_2.width,
			&orc.img_2.height);
	orc.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/r/3.xpm",
			&orc.img_3.width, &orc.img_3.height);
	orc.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/r/4.xpm", &orc.img_4.width, &orc.img_4.height);
	return (orc);
}
