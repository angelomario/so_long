/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_atack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:05:20 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/19 19:06:19 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

t_atack	set_orc_atack_right(t_vars vars)
{
	t_atack	orc;

	orc.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/ar/1.xpm", &orc.img_1.width, &orc.img_1.height);
	orc.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/ar/2.xpm", &orc.img_2.width, &orc.img_2.height);
	orc.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/ar/3.xpm", &orc.img_3.width, &orc.img_3.height);
	orc.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/ar/4.xpm", &orc.img_4.width, &orc.img_4.height);
	orc.img_5.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/ar/5.xpm", &orc.img_5.width, &orc.img_5.height);
	return (orc);
}

t_atack	set_orc_atack_left(t_vars vars)
{
	t_atack	orc;

	orc.img_1.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/al/1.xpm", &orc.img_1.width, &orc.img_1.height);
	orc.img_2.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/al/2.xpm", &orc.img_2.width, &orc.img_2.height);
	orc.img_3.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/al/3.xpm", &orc.img_3.width, &orc.img_3.height);
	orc.img_4.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/al/4.xpm", &orc.img_4.width, &orc.img_4.height);
	orc.img_5.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/orc/al/5.xpm", &orc.img_5.width, &orc.img_5.height);
	return (orc);
}
