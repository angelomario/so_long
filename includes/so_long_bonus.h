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

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libs/_ft_printf_/ft_printf.h"
# include "../libs/mlx_linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

struct		s_img;
struct		s_activity;
struct		s_pictures;
struct		s_point;
struct		s_activity;
struct		s_img;
struct		s_vars;
struct		s_map;
struct		s_data;

static int	g_next = 0;
static int	g_timer = 0;
static int	g_timer_move = 0;
static int	g_ter = 1000;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_activity
{
	int			colate;
	int			moves;
	int			door;
	int			total;
	int			in_move;
	int			next_img;
	int			alter;
	int			is_dead;
}				t_activity;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
	char		*path;
}				t_img;

typedef struct s_wallp
{
	void		*mlx;
	void		*win;
	t_img		wallpaper;
	char		**map;
}				t_wallp;

typedef struct s_run
{
	t_img		img_1;
	t_img		img_2;
	t_img		img_3;
	t_img		img_4;
	t_img		img_5;
	t_img		img_6;
}				t_run;

typedef struct s_standing
{
	t_img		img_1;
	t_img		img_2;
	t_img		img_3;
	t_img		img_4;

}				t_standing;

typedef struct s_death
{
	t_img		img_1;
	t_img		img_2;
	t_img		img_3;
	t_img		img_4;
	t_img		img_5;
}				t_death;

typedef struct s_atack
{
	t_img		img_1;
	t_img		img_2;
	t_img		img_3;
	t_img		img_4;
	t_img		img_5;
}				t_atack;

typedef struct s_world
{
	t_img		wall;
	t_img		food;
	t_img		floor;
	t_img		box_close;
	t_img		box_open;
	t_img		box_empty;
	t_img		door_open;
	t_img		door_close;
}				t_world;

typedef struct s_pictures
{
	t_run		rogue_rr;
	t_run		rogue_rl;
	t_death		rogue_dl;
	t_death		rogue_dr;
	t_standing	rogue_sl;
	t_standing	rogue_sr;
	t_standing	orc_sl;
	t_standing	orc_sr;
	t_run		orc_rr;
	t_run		orc_rl;
	t_atack		orc_ar;
	t_atack		orc_al;
	t_world		world;
	t_run		rogue_ur;
	t_run		rogue_ul;
	t_run		orc_ur;
	t_run		orc_ul;
}				t_pitures;

typedef struct s_enemy
{
	t_point		position;
	int			next_img;
	int			alter;
	int			in_move;
	char		direction;
	int			orc_see;
	int			timer_enemy;
	int			teo;
	int			index;
	int			to_attack;
	int			stop_attack;
}				t_enemy;

typedef struct s_vars
{
	void		*mlx;
	void		*window;
	char		**map;
	t_pitures	pictures;
	t_img		**animate;
	char		*direction;
	t_activity	*status;
	int			*rogue_see;
	t_enemy		*enemies;
	int			timer_pause;
}				t_vars;

// Valid
char			**get_mat(char **av);
int				is_valid_map(char **map);
int				is_valid_file(char *str, char *param);
void			check_map(char **map);

// Error and free
void			free_matriz(char **mat);
void			ft_quit_default(int error_type);
int				ft_quick_game(t_vars *vars);

// Click events
void			ft_game(char **map);
int				move(int key_code, t_vars *map);

// Utils
int				ft_strlen(char *str, char c, int i);
void			check_reach(t_vars vars, t_point rogue, t_point orc, int index);
void			detect_rogue(t_vars *vars);
void			rogue_die(t_vars vars, t_point position);
void			finish_game(t_vars *vars, int res);
void			death(t_vars vars, t_death p, t_point position);
void			move_all_diretion(t_vars *vars);
void			move_up(t_vars vars, t_point position);
void			move_down(t_vars vars, t_point position);
void			move_right(t_vars vars, t_point position);
void			move_left(t_vars vars, t_point position);
void			on_read_map(t_vars vars, char enemy);
char			*reset_direction(int i);
void			set_direction(t_vars vars, char direction);
int				ft_ch_in_str(char ch, char *str);
char			**ft_split(char *str);
int				ft_putstr(char *str);
int				ft_count_var_game(char **map, char var);
int				ft_countstr(char *str);
int				ft_countline(char **map);
int				have_valid_wall(char **map);
void			showmap(t_vars vars);
void			showimage(char ch, t_vars vars, t_point position);
void			fill(char **map, t_point size, t_point cur, char *to_fill);
void			flood_fill(char **tab, t_point size, t_point begin);
t_point			get_start_var(char **map, char var);
void			show_matriz(char **map, char *vars);
void			create_image(t_vars *vars);
void			delete_image(t_vars vars);
void			end_game(t_vars vars, t_point position);
int				animation(t_vars *vars);
char			*ft_itoa(int n);
char			*ft_strcat(char *str, char *num);

// RUN
t_run			set_rogue_run_right(t_vars vars);
t_run			set_rogue_run_left(t_vars vars);
t_run			set_orc_run_right(t_vars vars);
t_run			set_orc_run_left(t_vars vars);

// STANDING

t_standing		set_rogue_standing_right(t_vars vars);
t_standing		set_rogue_standing_left(t_vars vars);
t_standing		set_orc_standing_left(t_vars vars);
t_standing		set_orc_standing_right(t_vars vars);

// ATACK
t_atack			set_orc_atack_right(t_vars vars);
t_atack			set_orc_atack_left(t_vars vars);

// WORLD
t_world			set_world(t_vars vars);

// UP
t_run			set_rogue_up_right(t_vars vars);
t_run			set_rogue_up_left(t_vars vars);
t_run			set_orc_up_left(t_vars vars);
t_run			set_orc_up_right(t_vars vars);

// DEATH
t_death			set_rogue_death_l(t_vars vars);
t_death			set_rogue_death_r(t_vars vars);

// DELETE IMAGES
int				delete_run(t_vars vars);
int				delete_death(t_vars vars);
int				delete_standing(t_vars vars);
int				delete_up(t_vars vars);
int				delete_world(t_vars vars);
int				fee_animate(t_vars vars);

// SET EXTRA
void			set_direction(t_vars vars, char direction);
void			rm_direction(char *direction);
char			*reset_direction(int i);
int				get_direction_p(t_vars vars, char personal, t_point position);
void			show_this_image(t_vars vars, t_img image, t_point position);
void			speed(t_vars vars, t_run p, t_point position);
void			leave(t_vars vars, t_run p, t_point position);
void			speed_r(t_vars vars, t_run p, t_point position);
void			leave_r(t_vars vars, t_run p, t_point position);
void			show_status(t_vars vars);
void			reset_enemies_directions(t_vars *vars);

// ENEMY MOVE
void			enemy_right(t_vars vars, t_point position, t_enemy orc);
void			enemy_left(t_vars vars, t_point position, t_enemy orc);
void			enemy_up(t_vars vars, t_point position, t_enemy orc);
void			enemy_down(t_vars vars, t_point position, t_enemy orc);
void			enemy_attack(t_vars vars, t_point position, t_enemy orc);

// ENEMY RUNS
void			speed_reverse_enemy(t_vars vars, t_run p, t_point position,
					t_enemy orc);
void			leave_reverse_enemy(t_vars vars, t_run p, t_point position,
					t_enemy orc);
void			speed_enemy(t_vars vars, t_run p, t_point position,
					t_enemy orc);
void			leave_enemy(t_vars vars, t_run p, t_point position,
					t_enemy orc);
void			leave_p(t_vars vars, t_atack p, t_point position, t_enemy orc);
void			speed_p(t_vars vars, t_atack p, t_point position, t_enemy orc);

// IA ENEMY
void			brain_enemy(t_vars *vars);
void			update_position(t_vars *vars, char **map);
void			update_position(t_vars *vars, char **map);
void			initialize_enemies(t_vars *vars, char **map);
char			rand_direction(int min, int max);
int				get_index(t_vars vars, t_point position);
#endif
