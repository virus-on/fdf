/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:23:00 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/02 12:23:02 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct s_point	t_point;
struct					s_point
{
	float				x;
	float				y;
	float				z;
	int					rx;
	int					ry;
	float				b_x;
	float				b_y;
	float				b_z;
	int					clr;
};

typedef struct s_env	t_env;
struct					s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	int					z_scale;
	int					width;
	int					height;
	t_point				**points;
	int					x_off;
	int					y_off;
	int					zoom;
	int					map_w;
	int					mc[9];
	int					bc;
	int					tc;
};

typedef struct s_line	t_line;
struct					s_line
{
	int					err1;
	int					err2;
	int					init_x;
	int					init_y;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
};

# define PI 3.14159265359

t_env					*ft_mlx_init(int **map, int w, int h, int m_w);
char					**ft_readmap(int fd, int *i);
void					ft_init_clrs(t_env *e);
void					ft_redef_clr(t_env *e);
void					ft_update_pts(t_env *env, float ang, int axis);
void					x_trans(t_env *e, t_point *p);
void					y_trans(t_env *e, t_point *p);
void					draw_vertical(t_env *env);
void					draw_horizontal(t_env *env);
int						*ft_get_cord(t_env *env, t_point p1, t_point p2);
void					mlx_img_clear(t_env *env);
void					x_rotation(t_point *p, float angle);
void					y_rotation(t_point *p, float angle);
void					z_rotation(t_point *p, float angle);
float					ft_def_clr_top(t_env *e);
float					ft_def_clr_bottom(t_env *e);
void					ft_def_clr(t_env *e, t_point *p);
void					ft_init_clrs(t_env *e);
void					ft_putline(t_env *env, t_point p1, t_point p2);
void					ft_addchr(char **str, char c);
void					ft_backup_points(t_env *env);
int						**ft_norm(char **map);
int						ft_count_nums(char *str);
t_point					**ft_convert(int **map, int m_width);
int						ft_ext_r(int clr);
int						ft_ext_g(int clr);
int						ft_ext_b(int clr);
int						ft_mv_clr(t_point p1, t_point p2, int	x, int y);
int						draw(t_env *env);
int						*ft_read(char	*str);
int						check_key_state(int keycode, t_env *e);
int						check_key_state1(int keycode, t_env *e);

#endif
