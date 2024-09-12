/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:14:53 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/23 09:22:46 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	show_matriz(char **map, char *vars)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'E')
				ft_printf("\033[32m%c\033[0m", vars[3]);
			else if (map[y][x] == '1')
				ft_printf("\033[31m%c\033[0m", vars[0]);
			else if (map[y][x] == '0')
				ft_printf("\033[32m%c\033[0m", vars[1]);
			else if (map[y][x] == 'C')
				ft_printf("\033[35m%c\033[0m", vars[2]);
			else if (map[y][x] == 'P')
				ft_printf("\033[32m%c\033[0m", vars[4]);
			else
				ft_printf("\033[0m%c\033[0m", map[y][x]);
		}
		ft_printf("\n");
	}
}

int	quick_wallpaper(t_wallp *vars)
{
	free_matriz(vars->map);
	mlx_destroy_image(vars->mlx, vars->wallpaper.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
	return (0);
}

int	wallpaper_resp(int key_code, t_wallp *vars)
{
	if (key_code == 65307)
	{
		mlx_destroy_image(vars->mlx, vars->wallpaper.img);
		free_matriz(vars->map);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	if (key_code == 65293)
	{
		mlx_destroy_image(vars->mlx, vars->wallpaper.img);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		ft_game(vars->map);
	}
	return (0);
}

void	wallpaper(char **map)
{
	t_wallp	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 908, 563, "JULES");
	vars.wallpaper.img = mlx_xpm_file_to_image(vars.mlx,
			"assets_b/wallpapers/wallpaper.xpm", &vars.wallpaper.width,
			&vars.wallpaper.height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.wallpaper.img, 0, 0);
	vars.map = map;
	mlx_hook(vars.win, 2, 1L << 0, wallpaper_resp, &vars);
	mlx_hook(vars.win, 17, 1L << 0, quick_wallpaper, &vars);
	mlx_loop(vars.mlx);
}

int	main(int ac, char **av)
{
	char	**map;

	if ((ac != 2) || is_valid_file(av[1], ".ber") == 0)
		ft_quit_default(0);
	map = get_mat(av);
	check_map(map);
	map = get_mat(av);
	wallpaper(map);
	free_matriz(map);
	return (0);
}
