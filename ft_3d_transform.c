/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:22:54 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/04 14:22:56 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_trans(t_env *e, t_point *p)
{
	p->rx = (int)((p->x - p->y) * 0.866 * e->zoom + e->x_off);
}

void	y_trans(t_env *e, t_point *p)
{
	p->ry = (int)(p->z * e->z_scale + (p->x + p->y) * 0.5 * e->zoom + e->y_off);
}

void	x_rotation(t_point *p, float angle)
{
	register float	y_init;
	register float	z_init;

	y_init = p->y;
	z_init = p->z;
	p->y = (y_init * cosf(angle) + z_init * sinf(angle));
	p->z = (-y_init) * sinf(angle) + z_init * cosf(angle);
}

void	y_rotation(t_point *p, float angle)
{
	register float	x_init;
	register float	z_init;

	x_init = p->x;
	z_init = p->z;
	p->x = x_init * cos(angle) + (z_init) * sin(angle);
	p->z = (-x_init) * sin(angle) + z_init * cos(angle);
}

void	z_rotation(t_point *p, float angle)
{
	register float	y_init;
	register float	x_init;

	y_init = p->y;
	x_init = p->x;
	p->x = x_init * cosf(angle) - y_init * sinf(angle);
	p->y = x_init * sinf(angle) + y_init * cosf(angle);
}
