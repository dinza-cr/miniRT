/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:16:22 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/24 11:07:50 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_capital(char *info, t_world *world)
{
	if (!ft_strcmp(info, "A") && world->has_ambient)
		return (1);
	if (!ft_strcmp(info, "C") && world->has_camera)
		return (1);
	if (!ft_strcmp(info, "L") && world->has_light)
		return (1);
	return (0);
}

int	pars_sort(char *line, t_world *world)
{
	char	**info;

	info = ft_split(line, ' ');
	if (check_capital(info[0], world))
		return (free_split(info), 1);
	else if (!ft_strcmp(info[0], "A"))
		world->A =  cons_amblight(info, world);
	else if (!ft_strcmp(info[0], "C"))
		world->C = cons_camera(info, world);
	else if (!ft_strcmp(info[0], "L"))
		world->L = cons_light(info, world);
	else if (!strcmp(info[0], "sp"))
		add_sphere(info, world);
	else if (!strcmp(info[0], "pl"))
		add_plane(info, world);
	else if (!strcmp(info[0], "cy"))
		add_cylinder(info, world);
	free_split(info);
	return (0);
}

int	valid_world(t_world *world)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;

	if (!world)
		return (0);
	if (!world->has_ambient || !world->has_camera || !world->has_light)
		return (0);
	if (!world->A.valid || !world->C.valid || !world->L.valid)
		return (0);
	sp = world->spheres;
	while (sp)
	{
		if (!sp->valid)
			return (0);
		sp = sp->next;
	}
	pl = world->planes;
	while (pl)
	{
		if (!pl->valid)
			return (0);
		pl = pl->next;
	}
	cy = world->cylinders;
	while (cy)
	{
		if (!cy->valid)
			return (0);
		cy = cy->next;
	}
	return (1);
}

t_world	*parsing(char **argv)
{
	t_world	*res;
	char	*line;
	int		fd;

	res = cons_world();
	if (!res)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (free(res), NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (pars_sort(line, res))
		{
			printf("Error\n *explicit message of my choice*\n");
			free(line);
			close(fd);
			get_next_line(-1);
			return (res);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (valid_world(res))
		res->valid = 1;
	return (res);
}
