/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:48:45 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/19 12:31:41 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "../Amblight/amblight.h"
# include "../Camera/camera.h"
# include "../Light/light.h"

typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_shape		t_shape;

typedef struct s_world
{
	int			valid;
	int			has_ambient;
	int			has_camera;
	int			has_light;

	t_amblight	amb;
	t_camera	cam;
	t_light		light;
	t_shape		*shapes;
}	t_world;

//constructeur
t_world		*cons_world(void);

//destructeur
void		dest_world(t_world *world);

t_world		*default_world(void);
#endif