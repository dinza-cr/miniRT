/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:16:22 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 16:51:24 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	check_capital(char *info, t_scene *scene)
{
	if (!ft_strcmp(info, "A") && scene->has_ambient)
		return (1);
	if (!ft_strcmp(info, "C") && scene->has_camera)
		return (1);
	if (!ft_strcmp(info, "L") && scene->has_light)
		return (1);
	return (0);
}

int	pars_sort(char *line, t_scene *scene)
{
	char **info;

	info = ft_split(line, ' ');
	if (check_capital(info[0], scene))
		return (free_split(info), 1);
	else if (!ft_strcmp(info[0], "A"))
		scene->A =  cons_amblight(info, scene);
	else if (!ft_strcmp(info[0], "C"))
		scene->C = cons_camera(info, scene);
	else if (!ft_strcmp(info[0], "L"))
		scene->L = cons_light(info, scene);
	else if (!strcmp(info[0], "sp"))
		add_sphere(info, scene);
	else if (!strcmp(info[0], "pl"))
		add_plane(info, scene);
	else if (!strcmp(info[0], "cy"))
		add_cylinder(info, scene);
	free_split(info);
	return (0);
}

int valid_scene(t_scene *scene)
{
	t_sphere	*sp;
	t_plane		*pl;
	t_cylinder	*cy;
	
	if (!scene)
		return (0);
	if (!scene->has_ambient || !scene->has_camera || !scene->has_light)
		return (0);
	if (!scene->A.valid || !scene->C.valid || !scene->L.valid)
		return (0);
	sp = scene->spheres;
	while (sp)
	{
		if (!sp->valid)
			return (0);
		sp = sp->next;
	}
	pl = scene->planes;
	while (pl)
	{
		if (!pl->valid)
			return (0);
		pl = pl->next;
	}
	cy = scene->cylinders;
	while (cy)
	{
		if (!cy->valid)
			return (0);
		cy = cy->next;
	}
	return (1);
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
	if (valid_scene(res))
		res->valid = 1;
	return (res);
}
