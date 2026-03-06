/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:16:22 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/06 15:14:57 by dinza-cr         ###   ########.fr       */
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
		world->A =  pars_amblight(info, world);
	else if (!ft_strcmp(info[0], "C"))
		world->C = pars_camera(info, world);
	else if (!ft_strcmp(info[0], "L"))
		world->L = pars_light(info, world);
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
	t_shape *temp;

	if (!world)
		return (printf("Error\nInvalid world"), 1);
	if (!world->has_camera || !world->has_light)
		return (printf("Error\nWorld needs a camera and light\n"), 1);
	if ((world->has_ambient && !world->A.valid)
		|| (world->has_camera && !world->C.valid)
		|| (world->has_light && !world->L.valid))
		return (printf("Error\nInvalid scene.\n"), 1);
	temp = world->shapes;
	while (temp)
	{
		if (!temp->cylinder.valid && !temp->sphere.valid && !temp->plane.valid)
			return (printf("Error\nInvalid shapes.\n"), 1);
		temp = temp->next;
	}
	return (0);
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
			printf("Error\n Elements defined by a capital letter can only be declared once in the scene.\n");
			free(line);
			close(fd);
			get_next_line(-1);
			return (res);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!valid_world(res))
		res->valid = 1;
	return (res);
}
