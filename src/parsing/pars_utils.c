/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 18:35:03 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 16:04:03 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	count_elem(char **t)
{
	int	i;

	i = 0;
	while (t && t[i])
		i++;
	return (i);
}

void	free_split(char **t)
{
	int	i;

	if (!t)
		return ;
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
}

int	in_range(double x, double a, double b)
{
	return (x >= a && x <= b);
}

t_tuple	get_point(char *info)
{
	char	**buff;
	t_tuple	res;
	t_tuple	err;

	err = cons_point(0, 0, 0);
	err.w = -1;
	buff = ft_split(info, ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), err);
	res = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	return (res);
}

t_tuple get_vector(char *info)
{
	char	**buff;
	t_tuple	res;
	t_tuple	err;

	err = cons_point(0, 0, 0);
	err.w = -1;
	buff = ft_split(info, ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), err);
	res = cons_vector(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res.x, -1.0, 1.0)
		|| !in_range(res.y, -1.0, 1.0)
		|| !in_range(res.z, -1.0, 1.0)
		|| top_magnitude(res) < EPSILON)
		return (err);
	res = top_normalize(res);
	return (res);
}

t_color get_color(char *info)
{
	char	**buff;
	t_color	res;
	t_color	err;

	err = cons_color(0, 0, 0);
	err.r = -1;
	buff = ft_split(info, ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), err);
	res = cons_color(ft_atod(buff[0]) / 255,
			ft_atod(buff[1]) / 255, ft_atod(buff[2]) / 255);
	free_split(buff);
	if (res.r < 0 || res.r > 1
		|| res.g < 0 || res.g > 1
		|| res.b < 0 || res.b > 1)
		return (err);
	return (res);
}
