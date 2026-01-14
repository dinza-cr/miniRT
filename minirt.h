/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:30:44 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/13 18:36:31 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT
# define MINI_RT


typedef struct s_tuple
{
	int	x;
	int	y;
	int	z;
	int	w; // 1 for points 0 for vectors
} t_tuple;

#endif