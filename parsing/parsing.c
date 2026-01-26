/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:16:22 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 14:56:12 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	pars_sort(char *line, t_scene *scene)
{
	char **elements;
	int i;

	elements = ft_split(line, ' ');
	if (!ft_strcmp(elements[0], "A") && !scene->has_ambient)
		scene->A =  cons_amblight(elements, scene);
	else if (!ft_strcmp(elements[0], "C") && !scene->has_camera)
		scene->C = cons_camera(elements, scene);
	else if (!ft_strcmp(elements[0], "L") && !scene->has_light)
		scene->L = cons_light(elements, scene);
	else if (!strcmp(elements[0], "sp"))
		add_sphere(elements, scene);
	else if (!strcmp(elements[0], "pl"))
		add_plane(elements, scene);
	else if (!strcmp(elements[0], "cy"))
		add_cylinder(elements, scene);
	i = 0;
	free_split(elements);
	return (0);
}

t_scene *parsing(char **argv)
{
	t_scene *res;
	char	*line;
	int		fd;

	res = cons_scene();
	if (!res)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (res);
	line = get_next_line(fd);
	while (line)
	{
		if (pars_sort(line, res))
			return (free(line), close(fd), res);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (res);
}
