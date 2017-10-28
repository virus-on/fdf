/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:24:57 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/22 16:25:02 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_redef_clr(t_env *e)
{
	register int	i;
	register int	j;

	i = 0;
	while ((e->points)[i])
	{
		j = 0;
		while (j < e->map_w)
		{
			ft_def_clr(e, &((e->points)[i][j]));
			j++;
		}
		i++;
	}
}

int			**ft_norm(char **map)
{
	int		**int_map;
	int		p[3];

	p[1] = 0;
	p[2] = 0;
	while (map[p[1]])
		p[1]++;
	int_map = (int **)malloc((p[1] + 1) * sizeof(int*));
	while (p[2] < p[1])
	{
		int_map[p[2]] = ft_read(map[p[2]]);
		p[2]++;
	}
	int_map[p[2]] = NULL;
	return (int_map);
}

int			ft_count_nums(char *str)
{
	register int	i;
	register int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j++;
		while (str[i] && str[i] != ' ')
			i++;
		while (str[i] && str[i] == ' ')
			i++;
	}
	return (j);
}

t_point		**ft_convert(int **map, int m_width)
{
	t_point			**out;
	register int	i;
	register int	j;
	register int	k;

	i = 0;
	while (map[i])
		i++;
	out = (t_point**)malloc(sizeof(t_point*) * (i + 1));
	j = 0;
	while (j < i)
	{
		k = 0;
		out[j] = (t_point*)malloc(sizeof(t_point) * m_width);
		while (k < m_width)
		{
			out[j][k].x = k - m_width / 2;
			out[j][k].y = j - i / 2;
			out[j][k].z = map[j][k];
			k++;
		}
		j++;
	}
	out[j] = NULL;
	return (out);
}
