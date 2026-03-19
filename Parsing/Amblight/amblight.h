/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amblight.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:42:51 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/18 16:43:08 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBLIGHT_H
# define AMBLIGHT_H

# include "../../Exec/Color/color.h"
# include "../libft/libft.h"

typedef struct s_world	t_world;

typedef struct s_amblight
{
	int		valid;
	double	ratio;
	t_color	color;
}	t_amblight;

//parsing
t_amblight	pars_amblight(char **info, t_world *world);

//utils
int			count_elem(char **t);
void		free_split(char **t);

#endif