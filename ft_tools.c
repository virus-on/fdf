/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 14:29:44 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/04 14:29:45 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_pixput(t_env *e, int x, int y, int clr)
{
	char	*pixel;
	int		p;

	if (x > 0 && y > 0 && x < e->width && y < e->height)
	{
		pixel = mlx_get_data_addr(e->img, &p, &p, &p);
		p = 1920 * y * 4 + x * 4;
		pixel[p + 0] = ft_ext_r(clr);
		pixel[p + 1] = ft_ext_g(clr);
		pixel[p + 2] = ft_ext_b(clr);
	}
}

void	mlx_img_clear(t_env *e)
{
	char	*pixel;
	int		p;

	pixel = mlx_get_data_addr(e->img, &p, &p, &p);
	ft_bzero(pixel, 1920 * 1080 * 4);
}

void	ft_putline(t_env *e, t_point p, t_point q)
{
	t_line	line;

	line.init_x = p.rx;
	line.init_y = p.ry;
	line.dx = abs(q.rx - p.rx);
	line.dy = abs(q.ry - p.ry);
	line.sx = p.rx < q.rx ? 1 : -1;
	line.sy = p.ry < q.ry ? 1 : -1;
	line.err1 = line.dx - line.dy;
	while (p.rx != q.rx || p.ry != q.ry)
	{
		mlx_pixput(e, p.rx, p.ry, ft_mv_clr(p, q, line.init_x, line.init_y));
		line.err2 = line.err1 * 2;
		if (line.err2 > -(line.dy))
		{
			line.err1 -= line.dy;
			p.rx += line.sx;
		}
		if (line.err2 < line.dx)
		{
			line.err1 += line.dx;
			p.ry += line.sy;
		}
	}
}

void	ft_addchr(char **str, char c)
{
	char	*temp;

	if (*str)
	{
		temp = ft_strnew(ft_strlen(*str));
		ft_strcpy(temp, *str);
		free(*str);
		*str = ft_strnew(ft_strlen(temp) + 1);
		ft_strcpy(*str, temp);
		(*str)[ft_strlen(*str)] = c;
		free(temp);
	}
	else
	{
		*str = ft_strnew(1);
		**str = c;
	}
}

int		*ft_read(char *str)
{
	int				*out;
	register int	i;
	register int	j;

	out = (int*)malloc(sizeof(int) * ft_strlen(str));
	i = 0;
	j = 0;
	out[i++] = ft_atoi(str);
	while (ft_strlen(&(str[j])) != 0)
	{
		while (str[j] != ' ' && str[j])
			j++;
		while (str[j] == ' ')
			j++;
		out[i++] = ft_atoi(&(str[j]));
	}
	return (out);
}
