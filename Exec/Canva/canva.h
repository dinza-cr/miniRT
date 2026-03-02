/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canva.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinza-cr <dinza-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:35:25 by dinza-cr          #+#    #+#             */
/*   Updated: 2026/02/27 18:47:15 by dinza-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVA_H
# define CANVA_H

typedef struct s_color	t_color;

typedef struct s_canva
{
	int		width;
	int		height;

	void	*mlx;
	void	*win;

	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;

	t_color	*pixels;
}	t_canva;

//constructeur
t_canva		*cons_canva(int width, int height);

//destructeur
void		dest_canva(t_canva *canva);

//canva actions
void		write_pixel(t_canva *canva, int x_pos, int y_pos, t_color pixel);
int			ft_convertcolor(double a);
void		write_header(int fd, t_canva *canva);
void		canvas_to_ppm(t_canva *canva);
void		canva_to_mlx(t_canva *canva);
int			rgb_to_int(double r, double g, double b);
int			key_hook(int keycode, t_canva *c);
void		addr_put_pixel(t_canva *canva, int x, int y, int color);
#endif