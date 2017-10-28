/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:25:48 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/04 14:25:50 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_ext_r(int clr)
{
	return ((int)(((clr >> 16) & 0xFF)));
}

int		ft_ext_g(int clr)
{
	return ((int)(((clr >> 8) & 0xFF)));
}

int		ft_ext_b(int clr)
{
	return ((int)((clr & 0xFF)));
}

int		ft_mv_clr(t_point p, t_point q, int x, int y)
{
	float			stps;
	float			cs;
	float			s;
	register int	p1r;
	register int	p1g;

	p1r = ft_ext_r(p.clr);
	p1g = ft_ext_g(p.clr);
	stps = sqrt(pow((q.rx - x), 2) + pow((q.ry - y), 2));
	cs = -sqrt((p.rx - q.rx) * (p.rx - q.rx) + (p.ry - q.ry) * (p.ry - q.ry));
	cs += stps;
	s = (ft_ext_r(q.clr) - p1r) / stps;
	x = (p1r + (int)(s * cs)) * 0x10000;
	s = (ft_ext_g(q.clr) - p1g) / stps;
	x += (p1g + (int)(s * cs)) * 0x100;
	s = (ft_ext_b(q.clr) - ft_ext_b(p.clr)) / stps;
	x += ft_ext_b(p.clr) + (int)(s * cs);
	return (x);
}

void	ft_def_clr(t_env *e, t_point *p)
{
	int			stps;
	static int	max = 0;
	static int	min = -1;
	float		s;

	if (!max && min == -1)
	{
		max = ft_def_clr_top(e);
		min = ft_def_clr_bottom(e);
	}
	stps = max - min;
	if (!stps)
	{
		p->clr = e->mc[e->bc];
		return ;
	}
	s = ((float)(ft_ext_r(e->mc[e->tc]) - ft_ext_r(e->mc[e->bc])) / stps);
	p->clr = (ft_ext_r(e->mc[e->bc]) + s * (p->b_z - min)) * 0x10000;
	s = ((float)(ft_ext_g(e->mc[e->tc]) - ft_ext_g(e->mc[e->bc])) / stps);
	p->clr += (ft_ext_g(e->mc[e->bc]) + s * (p->b_z - min)) * 0x100;
	s = ((float)(ft_ext_b(e->mc[e->tc]) - ft_ext_b(e->mc[e->bc])) / stps);
	p->clr += ft_ext_b(e->mc[e->bc]) + s * (p->b_z - min);
}
