/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:21:00 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/03 16:38:53 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

# include "parsing/world.h"
# include "parsing/amblight.h"
# include "parsing/camera.h"
# include "parsing/light.h"
# include "parsing/sphere.h"
# include "parsing/cylinder.h"
# include "parsing/plane.h"
# include "parsing/shape.h"

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

#endif
