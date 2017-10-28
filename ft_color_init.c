/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:24:31 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/04 14:24:33 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_def_clr_top(t_env *e)
{
	register int	i;
	register int	j;
	register int	k;

	i = 0;
	k = e->points[0][0].b_z;
	while ((e->points)[i])
	{
		j = 0;
		while (j < e->map_w)
		{
			if (e->points[i][j].b_z > k)
				k = e->points[i][j].b_z;
			j++;
		}
		i++;
	}
	return (k);
}

float	ft_def_clr_bottom(t_env *e)
{
	register int	i;
	register int	j;
	register int	k;

	i = 0;
	k = e->points[0][0].b_z;
	while ((e->points)[i])
	{
		j = 0;
		while (j < e->map_w)
		{
			if (e->points[i][j].b_z < k)
				k = e->points[i][j].b_z;
			j++;
		}
		i++;
	}
	return (k);
}

void	ft_init_clrs(t_env *e)
{
	e->mc[0] = 0x00ffffff;
	e->mc[1] = 0x00ff0000;
	e->mc[2] = 0x00646464;
	e->mc[3] = 0x0000ff00;
	e->mc[4] = 0x000000ff;
	e->mc[5] = 0x00ff00ff;
	e->mc[6] = 0x0000ffff;
	e->mc[7] = 0x00ffff00;
	e->mc[8] = 0x00000000;
}

int		check_key_state1(int keycode, t_env *e)
{
	if (keycode == 12)
		ft_update_pts(e, 0.11, 2);
	if (keycode == 14)
		ft_update_pts(e, -0.11, 2);
	if (keycode == 30)
		e->z_scale += 1;
	if (keycode == 33)
		e->z_scale -= 1;
	if (keycode == 17)
	{
		e->bc += 1;
		if (e->bc > 8)
			e->bc = 0;
		ft_redef_clr(e);
	}
	if (keycode == 15)
	{
		e->tc += 1;
		if (e->tc > 8)
			e->tc = 0;
		ft_redef_clr(e);
	}
	return (draw(e));
}
