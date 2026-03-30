/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:21:34 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/30 20:07:59 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	parse_reflective(char *token, double *reflective)
{
	char	*end;

	*reflective = strtod(token, &end);
	if (end == token)
		return (0);
	if (*end == '\n')
		end++;
	if (*end != '\0')
		return (0);
	return (1);
}

//constructor
t_plane	cons_plane(void)
{
	t_plane	res;

	res.valid = 0;
	res.coord = cons_point(0, 0, 0);
	res.normal = cons_vector(0, 0, 0);
	res.has_texture = 0;
	res.texture_loaded = 0;
	res.texture_path = NULL;
	res.texture_img = NULL;
	res.texture_addr = NULL;
	res.texture_width = 0;
	res.texture_height = 0;
	res.texture_bpp = 0;
	res.texture_line_len = 0;
	res.texture_endian = 0;
	return (res);
}

t_shape	*pars_plane(char **info)
{
	t_shape	*res;
	char	*path;
	int		elem;
	double	reflective;

	res = cons_shape();
	if (!res)
		return (NULL);
	elem = count_elem(info);
	if (elem < 4 || elem > 6)
		return (res);
	res->plane.coord = get_point(info[1]);
	if (res->plane.coord.w == -1)
		return (res);
	res->plane.normal = get_vector(info[2]);
	if (res->plane.normal.w == -1)
		return (res);
	res->material.color = get_color(info[3]);
	if (res->material.color.r == -1)
		return (res);
	if (elem == 5)
	{
		if (parse_reflective(info[4], &reflective))
		{
			if (!in_range(reflective, 0.0, 1.0))
				return (res);
			res->material.reflective = reflective;
		}
		else
		{
			path = ft_strtrim(info[4], "\n");
			if (!path)
				return (res);
			res->plane.has_texture = 1;
			res->plane.texture_path = path;
		}
	}
	else if (elem == 6)
	{
		path = ft_strtrim(info[4], "\n");
		if (!path)
			return (res);
		res->plane.has_texture = 1;
		res->plane.texture_path = path;
		if (!parse_reflective(info[5], &reflective)
			|| !in_range(reflective, 0.0, 1.0))
			return (res);
		res->material.reflective = reflective;
	}
	res->transformation = pl_transform(res);
	res->inv_transfo = mop_inverse(res->transformation);
	res->plane.valid = 1;
	return (res);
}

void	add_plane(char **info, t_world *world)
{
	t_shape	*new;

	new = pars_plane(info);
	if (!new)
		return ;
	new->next = world->shapes;
	world->shapes = new;
}

t_matrix	pl_transform(t_shape *s)
{
	t_tuple		y_axis;
	t_tuple		helper;
	t_tuple		x_axis;
	t_tuple		z_axis;
	t_matrix	rotation;
	t_matrix	translation;

	y_axis = s->plane.normal;
	if (fabs(y_axis.z) < 1 - EPSILON)
		helper = cons_vector(0, 0, 1);
	else
		helper = cons_vector(1, 0, 0);
	x_axis = top_cross(helper, y_axis);
	x_axis = top_normalize(x_axis);
	z_axis = top_cross(y_axis, x_axis);
	rotation = cons_mat4(
			x_axis.x, y_axis.x, z_axis.x, 0,
			x_axis.y, y_axis.y, z_axis.y, 0,
			x_axis.z, y_axis.z, z_axis.z, 0,
			0, 0, 0, 1);
	translation = trsf_translation(s->plane.coord.x,
			s->plane.coord.y, s->plane.coord.z);
	return (mop_multimat(translation, rotation));
}

t_intersections	plane_intersect(t_shape *s, t_ray r)
{
	t_intersections	res;
	double			t;

	if (fabs(r.direction.y) < EPSILON)
		return (cons_intersections(0));
	t = (-r.origin.y) / (r.direction.y);
	if (t <= EPSILON)
		return (cons_intersections(0));
	res = cons_intersections(1);
	if (!res.solutions)
		return (cons_intersections(0));
	res.solutions[0] = cons_intersection(t, s);
	return (res);
}

static void	load_plane_texture(t_shape *shape, void *mlx)
{
	t_plane	*plane;

	plane = &shape->plane;
	if (!plane->valid || !plane->has_texture || plane->texture_loaded)
		return ;
	plane->texture_img = mlx_xpm_file_to_image(mlx, plane->texture_path,
			&plane->texture_width, &plane->texture_height);
	plane->texture_loaded = 1;
	if (!plane->texture_img)
	{
		plane->has_texture = 0;
		return ;
	}
	plane->texture_addr = mlx_get_data_addr(plane->texture_img,
			&plane->texture_bpp, &plane->texture_line_len, &plane->texture_endian);
	if (!plane->texture_addr)
	{
		mlx_destroy_image(mlx, plane->texture_img);
		plane->texture_img = NULL;
		plane->has_texture = 0;
	}
}

void	load_world_plane_textures(t_world *world, void *mlx)
{
	t_shape	*shape;

	if (!world || !mlx)
		return ;
	shape = world->shapes;
	while (shape)
	{
		load_plane_texture(shape, mlx);
		shape = shape->next;
	}
}

void	destroy_world_plane_textures(t_world *world, void *mlx)
{
	t_shape	*shape;

	if (!world)
		return ;
	shape = world->shapes;
	while (shape)
	{
		if (mlx && shape->plane.texture_img)
			mlx_destroy_image(mlx, shape->plane.texture_img);
		shape->plane.texture_img = NULL;
		shape->plane.texture_addr = NULL;
		if (shape->plane.texture_path)
			free(shape->plane.texture_path);
		shape->plane.texture_path = NULL;
		shape = shape->next;
	}
}

t_color	plane_texture_at(t_shape *s, t_tuple world_point)
{
	t_plane	*plane;
	t_tuple	p;
	int		x;
	int		y;
	char	*pixel;
	int		packed;

	plane = &s->plane;
	if (!plane->has_texture || !plane->texture_img || !plane->texture_addr)
		return (s->material.color);
	p = mop_multitup(s->inv_transfo, world_point);
	x = (int)((p.x + 0.5) * plane->texture_width);
	y = (int)((0.5 - p.z) * plane->texture_height);
	if (x < 0 || y < 0 || x >= plane->texture_width || y >= plane->texture_height)
		return (s->material.color);
	pixel = plane->texture_addr
		+ (y * plane->texture_line_len + x * (plane->texture_bpp / 8));
	packed = *(unsigned int *)pixel;
	return (cons_color(((packed >> 16) & 0xFF) / 255.0,
			((packed >> 8) & 0xFF) / 255.0,
			(packed & 0xFF) / 255.0));
}
