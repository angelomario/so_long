/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquissan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:08:41 by aquissan          #+#    #+#             */
/*   Updated: 2024/07/24 10:08:47 by aquissan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/_ft_printf_/ft_printf.h"
# include "../libs/mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

struct	s_pictures;
struct	s_point;
struct	s_activity;
struct	s_img;
struct	s_vars;
struct	s_map;
struct	s_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_activity
{
	int			colate;
	int			moves;
	int			total_colate;
}				t_activity;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
	char		*path;
}				t_img;

typedef struct s_pictures
{
	t_img		rogue_left;
	t_img		rogue_run_left;
	t_img		rogue_run_right;
	t_img		rogue_right;
	t_img		rogue_death_c_right;
	t_img		rogue_death_c_left;
	t_img		rogue_death_left;
	t_img		rogue_death_right;
	t_img		enemy_left;
	t_img		enemy_right;
	t_img		enemy_run_right;
	t_img		enemy_run_left;
	t_img		floor_1;
	t_img		floor_2;
	t_img		food;
	t_img		trunk_closed;
	t_img		trunk_food_open;
	t_img		trunk_open;
	t_img		door_1;
	t_img		door_dark_1;
	t_img		door_dark_pl;
	t_img		door_dark_pr;
	t_img		door_open;
	t_img		wall_1;
	t_img		door_2;
}				t_pitures;

typedef struct s_vars
{
	void		*mlx;
	void		*window;
	t_pitures	pictures;
}				t_vars;

typedef struct s_map
{
	t_vars		vars;
	char		**map;
}				t_map;

typedef struct s_data
{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

// Valid
char			**get_mat(char **av);
int				is_valid_map(char **map);
int				is_valid_file(char *str, char *param);
void			check_map(char **map);

// Error and free
void			free_matriz(char **mat);
void			ft_quit_default(int error_type);
int				ft_quick_game(t_map *map);

// Click events
void			ft_game(char **map);
int				move(int key_code, t_map *map);
void			move_r(t_map *map, t_point position);
// void	show_person(char ch, t_vars vars, t_point position, t_pitures pictures);

// Utils
int				ft_strlen(char *str, char c, int i);
int				ft_ch_in_str(char ch, char *str);
char			**ft_split(char *str);
int				ft_putstr(char *str);
void			my_pixel_put(t_data *data, int x, int y, int color);
int				ft_count_var_game(char **map, char var);
int				ft_countstr(char *str);
int				ft_countline(char **map);
int				have_valid_wall(char **map);
void			showmap(char **map, t_vars vars);
void			showimage(char ch, t_vars vars, t_point position,
					t_pitures pictures);
void			set_path(t_pitures *pictures);
void			fill(char **map, t_point size, t_point cur, char *to_fill);
void			flood_fill(char **tab, t_point size, t_point begin);
t_point			get_start_var(char **map, char var);
int				count_var(char **map, char var);
void			show_matriz(char **map, char *vars);
void			create_image(t_pitures *pictures, t_vars vars);
void			delete_image(t_vars vars);
void			end_game(t_map *map, t_point position);

#endif
