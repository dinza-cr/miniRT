/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:18:47 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/09 18:22:17 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	pars_camera(char **info, t_world *world)
{
	t_camera	res;
	t_tuple		to;

	res.valid = 0;
	world->has_camera = 1;
	if (count_elem(info) != 4)
		return (res);
	res.field_of_view = ft_atod(info[3]);
	if (!in_range(res.field_of_view, 0.0, 180.0))
		return (res);
	res = cons_camera(500, 500, res.field_of_view * (PI/180));
	res.coord = get_point(info[1]);
	if (res.coord.w == -1)
		return (res);
	res.orientation = get_vector(info[2]);
	if (res.orientation.z == -1)
		return (res);
	to = top_add(res.coord, res.orientation);
	res.transform = trsf_view_transform(res.coord, to, cons_vector(0, 1, 0));
	res.inv_transfo = mop_inverse(res.transform);
	res.valid = 1;
	return (res);
}

t_camera	cons_camera(int hsize, int vsize, double fov)
{
	t_camera	cam;
	double		aspect;

	cam.hsize = hsize;
	cam.vsize = vsize;
	cam.field_of_view = fov;
	cam.transform = cons_idmatrix();
	cam.half_view = tan(cam.field_of_view / 2.0);
	aspect = ((double)cam.hsize / (double)cam.vsize);
	if (aspect >= 1.0)
	{
		cam.half_width = cam.half_view;
		cam.half_height = cam.half_view / aspect;
	}
	else
	{
		cam.half_width = cam.half_view * aspect;
		cam.half_height = cam.half_view;
	}
	cam.pixel_size = (cam.half_width * 2.0) / (double)cam.hsize;
	return (cam);
}

t_ray	ray_for_pixel(t_camera camera, double px, double py)
{
	t_ray	res;
	double	xoffset;
	double	yoffset;
	double	world_x;
	double	world_y;
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

	xoffset = (px + 0.5) * camera.pixel_size;
	yoffset = (py + 0.5) * camera.pixel_size;
	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	pixel = mop_multitup(camera.inv_transfo,
			cons_point(world_x, world_y, -1.0));
	origin = mop_multitup(camera.inv_transfo, cons_point(0, 0, 0));
	direction = top_normalize(top_subs(pixel, origin));
	res = cons_ray(origin, direction);
	return (res);
}

t_canva	*render(t_camera camera, t_world *world)
{
	t_canva	*canva;
	t_ray	r;
	t_color	color;
	int		x;
	int		y;

	canva = cons_canva(world->C.hsize, world->C.vsize);
	y = 0;
	while (y < world->C.vsize)
	{
		x = 0;
		while (x < world->C.hsize)
		{
			r = ray_for_pixel(camera, x, y);
			color = color_at(world, r);
			write_pixel(canva, x, y, color);
			x++;
		}
		y++;
	}
	return (canva);
}
