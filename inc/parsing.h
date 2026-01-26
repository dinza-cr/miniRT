/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:21:00 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/01/26 14:35:46 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minirt.h"

typedef struct s_amblight // unique
{
	int		valid;
	double	ratio; // 0-1
	t_color	color;
}	t_amblight;

typedef struct s_camera // unique
{
	int valid;
	t_tuple	coord;
	t_tuple	orientation; // vector to normalize
	double		FOV; // 0 - 180 en degre
} t_camera;

typedef struct s_light // unique
{
	int		valid;
	t_tuple	coord;
	double	brightness; // 0-1
	t_color	color;
} t_light;

typedef struct s_sphere
{
	int				valid;
	t_tuple			coord;
	double			diameter;
	t_color			color;
	struct s_sphere	*next;
} t_sphere;

typedef struct s_plane
{
	int				valid;
	t_tuple 		coord;
	t_tuple			normal; // vector to normalise -1.0 - 1.0
	t_color			color;
	struct s_plane	*next;
} t_plane;

typedef struct s_cylinder
{
	int					valid;
	t_tuple 			coord;
	t_tuple 			axis; // vector to normalise -1.0 - 1.0
	double				diameter;
	double				height;
	t_color				color;
	struct s_cylinder	*next;
} t_cylinder;

typedef struct s_scene
{
	int			valid;
	int			has_ambient;
	int			has_camera;
	int			has_light;

	t_amblight	A;
	t_camera	C;
	t_light		L;
	t_sphere	*spheres;
	t_plane		*planes;
	t_cylinder	*cylinders;
} t_scene;

t_scene		*parsing(char **argv);
t_scene		*cons_scene(void);

//coms
t_amblight	cons_amblight(char **elements, t_scene *scene);
t_camera	cons_camera(char **elements, t_scene *scene);
t_light		cons_light(char **elements, t_scene *scene);
void		add_sphere(char **elements, t_scene *scene);
void	add_plane(char **elements, t_scene *scene);
void	add_cylinder(char **elements, t_scene *scene);

//utils
int			count_elem(char **t);
void		free_split(char **t);
int			in_range(double x, double a, double b);
#endif