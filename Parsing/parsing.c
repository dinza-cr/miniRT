/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:16:22 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/20 16:33:27 by dinza-cr         ###   ########.fr       */
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
		world->amb = pars_amblight(info, world);
	else if (!ft_strcmp(info[0], "C"))
		world->cam = pars_camera(info, world);
	else if (!ft_strcmp(info[0], "L"))
		world->light = pars_light(info, world);
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
	t_shape	*temp;

	if (!world)
		return (printf("Error\nInvalid world"), 1);
	if (!world->has_camera || !world->has_light || !world->has_ambient)
		return (printf("Error\nneed 1 camera, 1 spot and 1 ambient light\n"), 1);
	if ((world->has_ambient && !world->amb.valid)
		|| (world->has_camera && !world->cam.valid)
		|| (world->has_light && !world->light.valid))
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

int	check_rt(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 3 || str[len - 3] != '.'
		|| str[len - 2] != 'r' || str[len - 1] != 't')
		return (printf("Error\nnot a .rt file.\n"), 1);
	return (0);
}

t_world	*parsing(char **argv)
{
	t_world	*res;
	char	*line;
	int		fd;

	res = cons_world();
	if (check_rt(argv[1]))
		return (res);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !res)
		return (res);
	line = get_next_line(fd);
	while (line)
	{
		if (pars_sort(line, res))
		{
			printf("Error\n too many capital elements\n");
			return (free(line), close(fd), get_next_line(-1), res);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (!valid_world(res))
		res->valid = 1;
	return (res);
}
