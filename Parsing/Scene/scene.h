/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:48:45 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:06:15 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "../Amblight/amblight.h"
# include "../Camera/camera.h"
# include "../Light/light.h"

typedef struct s_sphere t_sphere;
typedef struct s_plane t_plane;
typedef struct s_cylinder t_cylinder;

typedef struct s_scene
{
	int			valid;
	int			has_ambient;
	int			has_camera;
	int			has_light;

	t_amblight	A;
	t_camera	C;
	t_light		L;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
}	t_scene;

//constructeur
t_scene		*cons_scene(void);

//destructeur
void		dest_scene(t_scene *scene);
#endif