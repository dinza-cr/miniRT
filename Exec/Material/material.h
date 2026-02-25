/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:52:43 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/25 11:14:09 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef struct s_material
{
	t_color color;
	double ambient;
	double diffuse;
	double specular;
	double shininess;
} t_material;

//constructeur
t_material cons_material();

//default material
t_material init_material();
#endif