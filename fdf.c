/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:13:54 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/01/30 15:13:57 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_readmap(int fd, int *i)
{
	char	*str;
	char	*full_str;
	char	*s_str;
	char	**map;

	full_str = ft_strnew(1);
	while (get_next_line(fd, &str))
	{
		s_str = ft_strjoin(full_str, str);
		ft_addchr(&s_str, '\n');
		free(full_str);
		full_str = s_str;
	}
	map = ft_strsplit(full_str, '\n');
	*i = ft_count_nums(*map);
	return (map);
}

int		check_key_state(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 123)
		e->x_off -= 5;
	if (keycode == 124)
		e->x_off += 5;
	if (keycode == 126)
		e->y_off -= 5;
	if (keycode == 125)
		e->y_off += 5;
	if (keycode == 24)
		e->zoom += 1;
	if (keycode == 27 && e->zoom > 1)
		e->zoom -= 1;
	if (keycode == 13)
		ft_update_pts(e, 0.11, 0);
	if (keycode == 1)
		ft_update_pts(e, -0.11, 0);
	if (keycode == 0)
		ft_update_pts(e, 0.11, 1);
	if (keycode == 2)
		ft_update_pts(e, -0.11, 1);
	return (check_key_state1(keycode, e));
}

void	ft_backup_points(t_env *env)
{
	register int	i;
	register int	j;

	i = 0;
	while ((env->points)[i])
	{
		j = 0;
		while (j < env->map_w)
		{
			(env->points)[i][j].b_x = (env->points)[i][j].x;
			(env->points)[i][j].b_y = (env->points)[i][j].y;
			(env->points)[i][j].b_z = (env->points)[i][j].z;
			j++;
		}
		i++;
	}
}

t_env	*ft_mlx_init(int **map, int width, int height, int m_width)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	env->points = ft_convert(map, m_width);
	env->width = width;
	env->height = height;
	env->bc = 0;
	env->tc = 0;
	env->zoom = 10;
	env->z_scale = -2;
	env->x_off = width / 2;
	env->y_off = height / 2;
	env->mlx = mlx_init();
	ft_init_clrs(env);
	env->win = mlx_new_window(env->mlx, width, height, "FDF");
	env->img = mlx_new_image(env->mlx, width, height);
	env->map_w = m_width;
	ft_backup_points(env);
	ft_init_clrs(env);
	ft_redef_clr(env);
	return (env);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	*e;
	int		i;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd > 2)
		{
			e = ft_mlx_init(ft_norm(ft_readmap(fd, &i)), 1920, 1080, i);
			close(fd);
			draw(e);
			mlx_hook(e->win, 2, 3, check_key_state, e);
			mlx_loop(e->mlx);
		}
		else
			ft_putstr_fd("Error\n", 2);
	}
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
