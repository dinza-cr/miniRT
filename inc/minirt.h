/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/03/25 14:15:21 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define EPSILON 0.00001
# define SHADOW_BIAS 0.0001
# define PI 3.14159265358979323846
# define MAX_SHAPE_SIZE 1000000.0

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

# include "../Exec/Tuples/tuple.h"
# include "../Exec/Color/color.h"
# include "../Exec/Matrix/matrix.h"
# include "../Exec/Canva/canva.h"
# include "../Exec/Ray/ray.h"
# include "../Exec/Intersection/intersection.h"
# include "../Exec/Material/material.h"
# include "../Exec/Comps/comps.h"

# include "parsing.h"

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

char		*get_next_line(int fd);

#endif