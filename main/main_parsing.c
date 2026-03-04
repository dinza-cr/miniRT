// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_parsing.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2026/01/23 11:58:18 by dinza-cr          #+#    #+#             */
// /*   Updated: 2026/03/04 16:18:02 by dinza-cr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../inc/minirt.h"

// int	main(int argc, char **argv)
// {
// 	t_world	*world;

// 	if (argc == 2)
// 	{
// 	world = parsing(argv);
// 	if (!world)
// 		return (printf("Parsing failed (NULL world)\n"), 1);

// // 	printf("==== world ====\n");
// 	printf("world valid      : %d\n", world->valid);
// 	printf("has ambient      : %d\n", world->has_ambient);
// 	printf("has camera       : %d\n", world->has_camera);
// 	printf("has light        : %d\n", world->has_light);

// 	/* ---------- AMBIENT ---------- */
// 	printf("\n---- AMBIENT LIGHT ----\n");
// 	if (!world->has_ambient)
// 		printf("no ambient light\n");
// 	else
// 	{
// 		printf("valid            : %d\n", world->A.valid);
// 		printf("ratio            : %f\n", world->A.ratio);
// 		printf("color            : R=%f G=%f B=%f\n",
// 			world->A.color.r, world->A.color.g, world->A.color.b);
// 	}
// 	/* ---------- CAMERA ---------- */
// 	printf("\n---- CAMERA ----\n");
// 	if (!world->has_camera)
// 		printf("no camera\n");
// 	else
// 	{
// 		printf("valid            : %d\n", world->C.valid);
// 		printf("coord            : x=%f y=%f z=%f\n",
// 			world->C.coord.x, world->C.coord.y, world->C.coord.z);
// 		printf("orientation      : x=%f y=%f z=%f\n",
// 			world->C.orientation.x,
// 			world->C.orientation.y,
// 			world->C.orientation.z);
// 		printf("FOV              : %f\n", world->C.field_of_view);
// 	}

// 	/* ---------- LIGHT ---------- */
// 	printf("\n---- LIGHT ----\n");
// 	if (!world->has_light)
// 		printf("no light\n");
// 	else
// 	{
// 		printf("valid            : %d\n", world->L.valid);
// 		printf("coord            : x=%f y=%f z=%f\n",
// 			world->L.coord.x, world->L.coord.y, world->L.coord.z);
// 		printf("brightness       : %f\n", world->L.brightness);
// 		printf("color            : R=%f G=%f B=%f\n",
// 			world->L.color.r, world->L.color.g, world->L.color.b);
// 	}

// 	/* ---------- SHAPES ---------- */
// 	printf("\n---- SHAPES ----\n");
// 	if (!world->shapes)
// 		printf("no sphapes\n");
// 	else
// 	{
// 		t_shape     *sp;
// 		int			i;

// 		sp = world->shapes;
// 		i = 0;
// 		while (sp)
// 		{
// 			printf("shape #%d\n", i);
// 			printf("  valid     : %d\n", sp->sphere.valid);
// 			printf("  coord     : x=%f y=%f z=%f\n",
// 				sp->sphere.coord.x, sp->sphere.coord.y, sp->sphere.coord.z);
// 			printf("  diameter  : %f\n", sp->sphere.diameter);
// 			printf("  color     : R=%f G=%f B=%f\n",
// 				sp->material.color.r, sp->material.color.g, sp->material.color.b);
// 			printf("\n");
// 			sp = sp->next;
// 			i++;
// 		}
// 	}

// 	// /* ---------- PLANES ---------- */
// 	// printf("\n---- PLANES ----\n");
// 	// if (!world->planes)
// 	// 	printf("no planes\n");
// 	// else
// 	// {
// 	// 	t_plane	*pl;
// 	// 	int		i;

// 	// 	pl = world->planes;
// 	// 	i = 0;
// 	// 	while (pl)
// 	// 	{
// 	// 		printf("plane #%d\n", i);
// 	// 		printf("  valid   : %d\n", pl->valid);
// 	// 		printf("  coord   : x=%f y=%f z=%f\n",
// 	// 			pl->coord.x, pl->coord.y, pl->coord.z);
// 	// 		printf("  normal  : x=%f y=%f z=%f\n",
// 	// 			pl->normal.x, pl->normal.y, pl->normal.z);
// 	// 		printf("  color   : R=%f G=%f B=%f\n",
// 	// 			pl->color.r, pl->color.g, pl->color.b);
// 	// 		printf("\n");
// 	// 		pl = pl->next;
// 	// 		i++;
// 	// 	}
// 	// }

// 	// /* ---------- CYLINDERS ---------- */
// 	// printf("\n---- CYLINDERS ----\n");
// 	// if (!world->cylinders)
// 	// 	printf("no cylinders\n");
// 	// else
// 	// {
// 	// 	t_cylinder	*cy;
// 	// 	int			i;

// 	// 	cy = world->cylinders;
// 	// 	i = 0;
// 	// 	while (cy)
// 	// 	{
// 	// 		printf("cylinder #%d\n", i);
// 	// 		printf("  valid    : %d\n", cy->valid);
// 	// 		printf("  coord    : x=%f y=%f z=%f\n",
// 	// 			cy->coord.x, cy->coord.y, cy->coord.z);
// 	// 		printf("  axis     : x=%f y=%f z=%f\n",
// 	// 			cy->axis.x, cy->axis.y, cy->axis.z);
// 	// 		printf("  diameter : %f\n", cy->diameter);
// 	// 		printf("  height   : %f\n", cy->height);
// 	// 		printf("  color    : R=%f G=%f B=%f\n",
// 	// 			cy->color.r, cy->color.g, cy->color.b);
// 	// 		printf("\n");
// 	// 		cy = cy->next;
// 	// 		i++;
// 	// 	}
// 	// }
// 	// printf("\n=======================\n");
// 	// dest_world(world);
// 	}
// 	else
// 		printf("Please add a world :)\n");
// 	return (0);
// }
