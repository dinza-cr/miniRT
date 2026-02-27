/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:18:47 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 15:58:04 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_camera	pars_camera(char **info, t_world *world)
{
	t_camera	res;
	t_tuple to;
	char		**buff;

	res.valid = 0;
	
	if (count_elem(info) != 4)
		return (res);

	res.field_of_view = ft_atod(info[3]);
	if (!in_range(res.field_of_view, 0.0, 180.0))
		return (res);

	res = cons_camera(500, 500, res.field_of_view * (PI/180));
		
	buff = ft_split(info[1], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.coord = cons_point(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	
	buff = ft_split(info[2], ',');
	if (!buff || count_elem(buff) != 3)
		return (free_split(buff), res);
	res.orientation = cons_vector(ft_atod(buff[0]), ft_atod(buff[1]), ft_atod(buff[2]));
	free_split(buff);
	if (!in_range(res.orientation.x, -1.0, 1.0) || !in_range(res.orientation.y, -1.0, 1.0) || !in_range(res.orientation.z, -1.0, 1.0) || top_magnitude(res.orientation) < EPSILON)
		return (res);
	res.orientation = top_normalize(res.orientation);

	to = top_add(res.coord, res.orientation);
	res.transform = trsf_view_transform(res.coord, to, cons_vector(0, 1, 0));
	res.valid = 1;
	world->has_camera = 1;
	return (res);
}

t_camera	cons_camera(int hsize, int vsize,double fov)
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
	t_ray res;

	double xoffset = (px + 0.5) * camera.pixel_size;
	double yoffset = (py + 0.5) * camera.pixel_size;
	
	double world_x = camera.half_width - xoffset;
	double world_y = camera.half_height - yoffset;

	t_tuple pixel = mop_multitup(mop_inverse(camera.transform), cons_point(world_x, world_y, -1.0));
	t_tuple origin = mop_multitup(mop_inverse(camera.transform), cons_point(0, 0, 0));
	t_tuple direction = top_normalize(top_subs(pixel, origin));

	res = cons_ray(origin, direction);
	return (res);
}

t_canva *render(t_camera camera,t_world *world)
{
	t_canva *canva = cons_canva(world->C.hsize, world->C.vsize);
	t_ray	r;
	t_color color;
	int x;
	int y;

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