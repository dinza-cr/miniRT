/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:58:18 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 14:52:38 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	t_scene	*scene;

	(void)argc;
	scene = parsing(argv);
	if (!scene)
		return (printf("Parsing failed (NULL scene)\n"), 1);

	printf("==== SCENE ====\n");
	printf("scene valid      : %d\n", scene->valid);
	printf("has ambient      : %d\n", scene->has_ambient);
	printf("has camera       : %d\n", scene->has_camera);
	printf("has light        : %d\n", scene->has_light);

	/* ---------- AMBIENT ---------- */
	printf("\n---- AMBIENT LIGHT ----\n");
	printf("valid            : %d\n", scene->A.valid);
	printf("ratio            : %f\n", scene->A.ratio);
	printf("color            : R=%f G=%f B=%f\n",
		scene->A.color.r, scene->A.color.g, scene->A.color.b);

	/* ---------- CAMERA ---------- */
	printf("\n---- CAMERA ----\n");
	printf("valid            : %d\n", scene->C.valid);
	printf("coord            : x=%f y=%f z=%f\n",
		scene->C.coord.x, scene->C.coord.y, scene->C.coord.z);
	printf("orientation      : x=%f y=%f z=%f\n",
		scene->C.orientation.x,
		scene->C.orientation.y,
		scene->C.orientation.z);
	printf("FOV              : %f\n", scene->C.FOV);

	/* ---------- LIGHT ---------- */
	printf("\n---- LIGHT ----\n");
	printf("valid            : %d\n", scene->L.valid);
	printf("coord            : x=%f y=%f z=%f\n",
		scene->L.coord.x, scene->L.coord.y, scene->L.coord.z);
	printf("brightness       : %f\n", scene->L.brightness);
	printf("color            : R=%f G=%f B=%f\n",
		scene->L.color.r, scene->L.color.g, scene->L.color.b);

	/* ---------- SPHERES ---------- */
	printf("\n---- SPHERES ----\n");
	if (!scene->spheres)
		printf("no spheres\n");
	else
	{
		t_sphere	*sp;
		int			i;

		sp = scene->spheres;
		i = 0;
		while (sp)
		{
			printf("sphere #%d\n", i);
			printf("  valid     : %d\n", sp->valid);
			printf("  coord     : x=%f y=%f z=%f\n",
				sp->coord.x, sp->coord.y, sp->coord.z);
			printf("  diameter  : %f\n", sp->diameter);
			printf("  color     : R=%f G=%f B=%f\n",
				sp->color.r, sp->color.g, sp->color.b);
			printf("\n");
			sp = sp->next;
			i++;
		}
	}

	/* ---------- PLANES ---------- */
	printf("\n---- PLANES ----\n");
	if (!scene->planes)
		printf("no planes\n");
	else
	{
		t_plane	*pl;
		int		i;

		pl = scene->planes;
		i = 0;
		while (pl)
		{
			printf("plane #%d\n", i);
			printf("  valid   : %d\n", pl->valid);
			printf("  coord   : x=%f y=%f z=%f\n",
				pl->coord.x, pl->coord.y, pl->coord.z);
			printf("  normal  : x=%f y=%f z=%f\n",
				pl->normal.x, pl->normal.y, pl->normal.z);
			printf("  color   : R=%f G=%f B=%f\n",
				pl->color.r, pl->color.g, pl->color.b);
			printf("\n");
			pl = pl->next;
			i++;
		}
	}

	/* ---------- CYLINDERS ---------- */
	printf("\n---- CYLINDERS ----\n");
	if (!scene->cylinders)
		printf("no cylinders\n");
	else
	{
		t_cylinder	*cy;
		int			i;

		cy = scene->cylinders;
		i = 0;
		while (cy)
		{
			printf("cylinder #%d\n", i);
			printf("  valid    : %d\n", cy->valid);
			printf("  coord    : x=%f y=%f z=%f\n",
				cy->coord.x, cy->coord.y, cy->coord.z);
			printf("  axis     : x=%f y=%f z=%f\n",
				cy->axis.x, cy->axis.y, cy->axis.z);
			printf("  diameter : %f\n", cy->diameter);
			printf("  height   : %f\n", cy->height);
			printf("  color    : R=%f G=%f B=%f\n",
				cy->color.r, cy->color.g, cy->color.b);
			printf("\n");
			cy = cy->next;
			i++;
		}
	}
	printf("\n=======================\n");
	free(scene);
	return (0);
}
