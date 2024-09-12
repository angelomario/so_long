/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 05:32:18 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/22 05:33:18 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	delete_run(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rr.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rr.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rr.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rr.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rr.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rr.img_6.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rl.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rl.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rl.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rl.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rl.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_rl.img_6.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rr.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rr.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rr.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rr.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rr.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rr.img_6.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rl.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rl.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rl.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rl.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rl.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_rl.img_6.img);
	return (1);
}

int	delete_death(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dl.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dl.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dl.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dl.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dl.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dr.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dr.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dr.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dr.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_dr.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_al.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_al.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_al.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_al.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_al.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ar.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ar.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ar.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ar.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ar.img_5.img);
	return (1);
}

int	delete_standing(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sl.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sl.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sl.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sl.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sr.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sr.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sr.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_sr.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sl.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sl.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sl.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sl.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sr.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sr.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sr.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_sr.img_4.img);
	return (1);
}

int	delete_up(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ur.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ur.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ur.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ur.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ur.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ur.img_6.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ul.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ul.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ul.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ul.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ul.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.rogue_ul.img_6.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ur.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ur.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ur.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ur.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ur.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ur.img_6.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ul.img_1.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ul.img_2.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ul.img_3.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ul.img_4.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ul.img_5.img);
	mlx_destroy_image(vars.mlx, vars.pictures.orc_ul.img_6.img);
	return (1);
}

int	delete_world(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.pictures.world.wall.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.food.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.floor.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.box_close.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.box_open.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.box_empty.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.door_open.img);
	mlx_destroy_image(vars.mlx, vars.pictures.world.door_close.img);
	return (1);
}
