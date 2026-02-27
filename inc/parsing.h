/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:21:00 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:06:20 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

# include "../Parsing/World/world.h"
# include "../Parsing/Amblight/amblight.h"
# include "../Parsing/Camera/camera.h"
# include "../Parsing/Light/light.h"
# include "../Parsing/Sphere/sphere.h"
# include "../Parsing/Cylinder/cylinder.h"
# include "../Parsing/Plane/plane.h"

//utils
int			count_elem(char **t);
void		free_split(char **t);
int			in_range(double x, double a, double b);
int			check_capital(char *info, t_world *world);
int			pars_sort(char *line, t_world *world);
int			valid_world(t_world *world);
t_world		*parsing(char **argv);
t_tuple		get_point(char *info);
t_tuple		get_vector(char *info);
t_color		get_color(char *info);

int			safe_exit(t_canva *canva, t_world *world);

#endif