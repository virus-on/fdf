/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:01:22 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/08 16:01:24 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		draw(t_env *env)
{
	mlx_img_clear(env);
	ft_update_pts(env, 0, 0);
	draw_horizontal(env);
	draw_vertical(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (1);
}

void	ft_update_pts(t_env *env, float ang, int axis)
{
	register int	i;
	register int	j;

	i = 0;
	while ((env->points)[i])
	{
		j = 0;
		while (j < env->map_w)
		{
			if (axis == 0 && ang)
				x_rotation(&((env->points)[i][j]), ang);
			if (axis == 1 && ang)
				y_rotation(&((env->points)[i][j]), ang);
			if (axis == 2 && ang)
				z_rotation(&((env->points)[i][j]), ang);
			x_trans(env, &((env->points)[i][j]));
			y_trans(env, &((env->points)[i][j]));
			j++;
		}
		i++;
	}
}

void	draw_horizontal(t_env *env)
{
	register int	i;
	register int	j;

	i = 0;
	while ((env->points)[i])
	{
		j = 0;
		while (j < env->map_w - 1)
		{
			ft_putline(env, (env->points)[i][j], (env->points)[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	draw_vertical(t_env *env)
{
	register int	i;
	register int	j;

	i = 0;
	while (i < env->map_w)
	{
		j = 0;
		while ((env->points)[j + 1] && (env->points)[j])
		{
			ft_putline(env, (env->points)[j][i], (env->points)[j + 1][i]);
			j++;
		}
		i++;
	}
}
