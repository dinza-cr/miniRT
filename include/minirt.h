/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:36:40 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON 0.00001
# define PI 3.14159265358979323846

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

# include "exec/tuple.h"
# include "exec/color.h"
# include "exec/matrix.h"
# include "exec/canva.h"
# include "exec/ray.h"
# include "exec/intersection.h"
# include "exec/material.h"
# include "exec/comps.h"

# include "minirtt.h"

# include "parsing.h"

# include "libft.h"

char		*get_next_line(int fd);

#endif