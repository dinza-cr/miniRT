/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:30:13 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/15 18:33:39 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void free_canva(t_canva *canva)
{
	if (!canva)
		return ;
	if (canva->pixels)
		free(canva->pixels);
	free(canva);
}