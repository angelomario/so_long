/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:04:06 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/19 13:05:33 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_run	set_rogue_run_right(t_vars vars)
{
	t_run	rogue;

	rogue.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rr/-1.xpm", &rogue.img_1.width,
			&rogue.img_1.height);
	rogue.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rr/-2.xpm", &rogue.img_2.width,
			&rogue.img_2.height);
	rogue.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rr/-3.xpm",
			&rogue.img_3.width, &rogue.img_3.height);
	rogue.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rr/1.xpm", &rogue.img_4.width, &rogue.img_4.height);
	rogue.img_5.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rr/2.xpm", &rogue.img_5.width, &rogue.img_5.height);
	rogue.img_6.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/rr/3.xpm",
			&rogue.img_6.width, &rogue.img_6.height);
	return (rogue);
}

t_run	set_rogue_run_left(t_vars vars)
{
	t_run	rogue;

	rogue.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rl/-1.xpm", &rogue.img_1.width,
			&rogue.img_1.height);
	rogue.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rl/-2.xpm", &rogue.img_2.width,
			&rogue.img_2.height);
	rogue.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rl/-3.xpm",
			&rogue.img_3.width, &rogue.img_3.height);
	rogue.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rl/1.xpm", &rogue.img_4.width, &rogue.img_4.height);
	rogue.img_5.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/rogue/rl/2.xpm", &rogue.img_5.width, &rogue.img_5.height);
	rogue.img_6.img = mlx_xpm_file_to_image(vars.mlx, "assets_b/rogue/rl/3.xpm",
			&rogue.img_6.width, &rogue.img_6.height);
	return (rogue);
}

t_run	set_orc_run_right(t_vars vars)
{
	t_run	orc;

	orc.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rr/-1.xpm", &orc.img_1.width, &orc.img_1.height);
	orc.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rr/-2.xpm", &orc.img_2.width, &orc.img_2.height);
	orc.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rr/-3.xpm", &orc.img_3.width, &orc.img_3.height);
	orc.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rr/1.xpm", &orc.img_4.width, &orc.img_4.height);
	orc.img_5.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rr/2.xpm", &orc.img_5.width, &orc.img_5.height);
	orc.img_6.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rr/3.xpm", &orc.img_6.width, &orc.img_6.height);
	return (orc);
}

t_run	set_orc_run_left(t_vars vars)
{
	t_run	orc;

	orc.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rl/-1.xpm", &orc.img_1.width, &orc.img_1.height);
	orc.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rl/-2.xpm", &orc.img_2.width, &orc.img_2.height);
	orc.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rl/-3.xpm", &orc.img_3.width, &orc.img_3.height);
	orc.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rl/1.xpm", &orc.img_4.width, &orc.img_4.height);
	orc.img_5.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rl/2.xpm", &orc.img_5.width, &orc.img_5.height);
	orc.img_6.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/rl/3.xpm", &orc.img_6.width, &orc.img_6.height);
	return (orc);
}
