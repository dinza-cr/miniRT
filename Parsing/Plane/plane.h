/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:55:53 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 19:04:21 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"
typedef struct s_world t_world;



typedef struct s_plane
{
	int				valid;
	t_tuple			coord;
	t_tuple			normal;
	t_color			color;
	struct s_plane	*next;
}	t_plane;


//parsing
t_plane		*pars_plane(char **info);

//constructeur
t_plane		*cons_plane(void);

//destructeur
void		dest_planes(t_plane *pl);

//utils
void		add_plane(char **info, t_world *world);


#endif