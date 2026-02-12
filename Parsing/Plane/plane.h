/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:55:53 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:07:34 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"
typedef struct s_scene t_scene;



typedef struct s_plane
{
	int				valid;
	t_tuple			coord;
	t_tuple			normal;
	t_color			color;
	struct s_plane	*next;
}	t_plane;

//constructeur
t_plane		*init_plane(void);
t_plane		*cons_plane(char **info);

//add
void		add_plane(char **info, t_scene *scene);

//destructeur
void		dest_planes(t_plane *pl);

#endif