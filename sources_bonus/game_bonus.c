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

#include "../includes/so_long_bonus.h"

void	get_list_p(t_vars *vars)
{
	int		i;
	t_img	**tab;

	i = -1;
	tab = (t_img **)malloc(sizeof(t_img *) * 5);
	while (++i < 4)
		tab[i] = (t_img *)malloc(sizeof(t_img) * 4);
	tab[0][0] = vars->pictures.rogue_sl.img_1;
	tab[0][1] = vars->pictures.rogue_sl.img_2;
	tab[0][2] = vars->pictures.rogue_sl.img_3;
	tab[0][3] = vars->pictures.rogue_sl.img_4;
	tab[1][0] = vars->pictures.rogue_sr.img_1;
	tab[1][1] = vars->pictures.rogue_sr.img_2;
	tab[1][2] = vars->pictures.rogue_sr.img_3;
	tab[1][3] = vars->pictures.rogue_sr.img_4;
	tab[2][0] = vars->pictures.orc_sl.img_1;
	tab[2][1] = vars->pictures.orc_sl.img_2;
	tab[2][2] = vars->pictures.orc_sl.img_3;
	tab[2][3] = vars->pictures.orc_sl.img_4;
	tab[3][0] = vars->pictures.orc_sr.img_1;
	tab[3][1] = vars->pictures.orc_sr.img_2;
	tab[3][2] = vars->pictures.orc_sr.img_3;
	tab[3][3] = vars->pictures.orc_sr.img_4;
	tab[4] = NULL;
	vars->animate = tab;
}

void	on_read_map(t_vars vars, char enemy)
{
	t_point	rogue;
	t_point	pos;
	int		x;
	int		n;

	rogue = get_start_var(vars.map, 'P');
	n = ft_count_var_game(vars.map, enemy);
	if (g_next >= 4)
		g_next = 0;
	while (n--)
	{
		pos = vars.enemies[n].position;
		x = vars.enemies[n].orc_see;
		mlx_put_image_to_window(vars.mlx, vars.window,
			vars.animate[x][g_next].img, pos.x * 40, pos.y * 40);
	}
	if (!vars.status->is_dead)
		mlx_put_image_to_window(vars.mlx, vars.window,
			vars.animate[vars.rogue_see[0]][g_next].img, rogue.x * 40, rogue.y
			* 40);
	g_next++;
}

void	move_all_diretion(t_vars *vars)
{
	if ((vars->direction[0] == 'R'))
		move_right(*vars, get_start_var(vars->map, 'P'));
	else if ((vars->direction[0] == 'E'))
		move_left(*vars, get_start_var(vars->map, 'P'));
	else if ((vars->direction[0] == 'D'))
		move_down(*vars, get_start_var(vars->map, 'P'));
	else if ((vars->direction[0] == 'U'))
		move_up(*vars, get_start_var(vars->map, 'P'));
}

char	rand_direction(int min, int max)
{
	int		random;
	int		pid;
	char	dir;

	pid = (int)getpid();
	random = (min + rand() % (max - min + 1) + pid);
	random = (random % 4) + 1;
	if (random == 1)
		dir = 'R';
	else if (random == 2)
		dir = 'E';
	else if (random == 3)
		dir = 'U';
	else if (random == 4)
		dir = 'D';
	return (dir);
}

void	ft_game(char **map)
{
	t_vars	vars;

	if (!map)
		ft_quit_default(1);
	vars.map = map;
	vars.mlx = mlx_init();
	vars.window = mlx_new_window(vars.mlx, ft_countstr(map[0]) * 40,
			ft_countline(map) * 40, "JULES");
	create_image(&vars);
	get_list_p(&vars);
	vars.rogue_see = (int *)malloc(sizeof(int) * 2);
	vars.status = (t_activity *)malloc(sizeof(t_activity) * 1);
	vars.status[0] = (t_activity){0, 0, 0, ft_count_var_game(vars.map, 'C'), 0,
		1, 0, 0};
	vars.timer_pause = 0;
	vars.rogue_see[0] = get_direction_p(vars, 'P', get_start_var(vars.map,
				'P'));
	vars.direction = reset_direction(4);
	initialize_enemies(&vars, vars.map);
	mlx_hook(vars.window, 2, 1L << 0, move, &vars);
	mlx_hook(vars.window, 17, 1L << 0, ft_quick_game, &vars);
	mlx_loop_hook(vars.mlx, animation, &vars);
	showmap(vars);
	mlx_loop(vars.mlx);
}
