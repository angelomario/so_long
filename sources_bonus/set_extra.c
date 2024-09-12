/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 13:38:33 by aquissan          #+#    #+#             */
/*   Updated: 2024/08/23 13:39:48 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	show_this_image(t_vars vars, t_img image, t_point position)
{
	mlx_put_image_to_window(vars.mlx, vars.window,
		image.img,
		position.x * (image.width),
		position.y * image.height);
}

void	show_status(t_vars vars)
{
	int		mult;
	char	*status[7];

	system ("clear");
	status[0] = ft_itoa(vars.status->moves);
	status[1] = ft_itoa(vars.status->colate);
	status[2] = ft_itoa(vars.status->total);
	status[3] = ft_strcat("Moves: ", status[0]);
	status[4] = ft_strcat("Colate: ", status[1]);
	status[5] = ft_strcat(" / ", status[2]);
	status[6] = ft_strcat(status[4], status[5]);
	mult = -1;
	while (++mult < ft_countstr(vars.map[0]))
		mlx_put_image_to_window(vars.mlx, vars.window,
			vars.pictures.world.wall.img, mult * 40, 0);
	mlx_string_put(vars.mlx, vars.window, 40, 10, 0xff00ffff, status[3]);
	mlx_string_put(vars.mlx, vars.window, 40, 30, 0xff00ffff, status[6]);
	mult = -1;
	while (++mult < 7)
		free(status[mult]);
	show_matriz(vars.map, "#.CEP");
	ft_printf("Moves: \033[32m%d\033[0m\n", vars.status->moves);
	ft_printf("Colate: \033[32m%d / %d \033[0m\n",
		vars.status->colate, vars.status->total);
}
