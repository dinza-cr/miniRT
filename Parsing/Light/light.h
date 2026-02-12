/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:46:35 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/12 17:03:05 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "../../Exec/Color/color.h"
# include "../../Exec/Tuples/tuple.h"

typedef struct s_scene t_scene; 

typedef struct s_light // unique
{
	int		valid;
	t_tuple	coord;
	double	brightness;
	t_color	color;
}	t_light;

//constructeur
t_light		cons_light(char **info, t_scene *scene);

#endif