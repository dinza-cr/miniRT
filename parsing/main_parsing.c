/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:58:18 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/23 18:43:06 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int main(int argc, char **argv)
{
	t_scene *scene;

	if (argc == 2)
	{
		scene = parsing(argv);
		if (!scene || !scene->valid)
			return (1);
	}
	return (0);
}