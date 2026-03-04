/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:58:18 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/04 16:51:41 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	t_world	*world;

	if (argc == 2)
	{
	world = parsing(argv);
	if (!world)
		return (printf("Parsing failed (NULL world)\n"), 1);

// 	printf("==== world ====\n");
	printf("world valid      : %d\n", world->valid);
	printf("has ambient      : %d\n", world->has_ambient);
	printf("has camera       : %d\n", world->has_camera);
	printf("has light        : %d\n", world->has_light);

	/* ---------- AMBIENT ---------- */
	printf("\n---- AMBIENT LIGHT ----\n");
	if (!world->has_ambient)
		printf("no ambient light\n");
	else
	{
		printf("valid            : %d\n", world->A.valid);
		printf("ratio            : %f\n", world->A.ratio);
		printf("color            : R=%f G=%f B=%f\n",
			world->A.color.r, world->A.color.g, world->A.color.b);
	}
	/* ---------- CAMERA ---------- */
	printf("\n---- CAMERA ----\n");
	if (!world->has_camera)
		printf("no camera\n");
	else
	{
		printf("valid            : %d\n", world->C.valid);
		printf("coord            : x=%f y=%f z=%f\n",
			world->C.coord.x, world->C.coord.y, world->C.coord.z);
		printf("orientation      : x=%f y=%f z=%f\n",
			world->C.orientation.x,
			world->C.orientation.y,
			world->C.orientation.z);
		printf("FOV              : %f\n", world->C.field_of_view);
	}

	/* ---------- LIGHT ---------- */
	printf("\n---- LIGHT ----\n");
	if (!world->has_light)
		printf("no light\n");
	else
	{
		printf("valid            : %d\n", world->L.valid);
		printf("coord            : x=%f y=%f z=%f\n",
			world->L.coord.x, world->L.coord.y, world->L.coord.z);
		printf("brightness       : %f\n", world->L.brightness);
		printf("color            : R=%f G=%f B=%f\n",
			world->L.color.r, world->L.color.g, world->L.color.b);
	}

	/* ---------- SHAPES ---------- */
	printf("\n---- SHAPES ----\n");
	if (!world->shapes)
		printf("no sphapes\n");
	else
	{
		t_shape     *shapes;
		int			i;

		shapes = world->shapes;
		i = 0;
		while (shapes)
		{
            if (shapes->sphere.valid == 1)
            {
                printf("shape #%d [SPHERE]\n", i);
                printf("  valid     : %d\n", shapes->sphere.valid);
                printf("  coord     : x=%f y=%f z=%f\n",
                    shapes->sphere.coord.x, shapes->sphere.coord.y, shapes->sphere.coord.z);
                printf("  diameter  : %f\n", shapes->sphere.diameter);
                printf("  color     : R=%f G=%f B=%f\n",
                    shapes->material.color.r, shapes->material.color.g, shapes->material.color.b);
                printf("\n");
            }
            else if (shapes->plane.valid == 1)
            {
                printf("shape #%d [PLANE]\n", i);
                printf("  valid   : %d\n", shapes->plane.valid);
                printf("  coord   : x=%f y=%f z=%f\n",
                    shapes->plane.coord.x, shapes->plane.coord.y, shapes->plane.coord.z);
                printf("  normal  : x=%f y=%f z=%f\n",
                    shapes->plane.normal.x, shapes->plane.normal.y, shapes->plane.normal.z);
                printf("  color   : R=%f G=%f B=%f\n",
                    shapes->material.color.r, shapes->material.color.g, shapes->material.color.b);
                printf("\n");
            }
			else if (shapes->cylinder.valid == 1)
			{
				printf("shape #%d [CYLINDER]\n", i);
				printf("  valid    : %d\n", shapes->cylinder.valid);
				printf("  coord    : x=%f y=%f z=%f\n",
					shapes->cylinder.coord.x, shapes->cylinder.coord.y, shapes->cylinder.coord.z);
				printf("  axis     : x=%f y=%f z=%f\n",
					shapes->cylinder.axis.x, shapes->cylinder.axis.y, shapes->cylinder.axis.z);
				printf("  diameter : %f\n", shapes->cylinder.diameter);
				printf("  height   : %f\n", shapes->cylinder.height);
				printf("  color    : R=%f G=%f B=%f\n",
					shapes->material.color.r, shapes->material.color.g, shapes->material.color.b);
				printf("\n");
			}
			shapes = shapes->next;
			i++;
		}
	}
	}
	else
		printf("Please add a world :)\n");
	return (0);
}
