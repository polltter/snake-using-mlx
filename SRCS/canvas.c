/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:36 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 17:03:27 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/snake.h"

void	load_imgs(t_object *obj, char *path)
{
	
	obj->img.img = mlx_xpm_file_to_image(mlx()->mlx, path, &obj->img.w, &obj->img.h);
	obj->img.addr = mlx_get_data_addr(obj->img.img, \
	&obj->img.bits_per_pixel, &obj->img.line_length, &obj->img.endian);	
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return(*(unsigned int *)dst);
}

void	draw()
{
	mlx_put_image_to_window(mlx()->mlx, mlx()->mlx_win, (mlx()->img).img, 0, 0);
}

void	draw_obj(t_object *obj)
{
	for (int sx = 0; sx < obj->img.w; sx++)
		for (int sy = 0; sy < obj->img.h; sy++)
			my_mlx_pixel_put(&(mlx()->img), sx + obj->pos.x, sy + obj->pos.y, my_mlx_pixel_get(&(obj->img), sx, sy));
}

void	draw_rec(int x, int y, int color)
{
	for (int sx = 0; sx < GRID; sx++)
		for (int sy = 0; sy < GRID; sy++)
			my_mlx_pixel_put(&(mlx()->img), sx + x,  sy + y, color);
}
void	draw_clear()
{
	for (int sx = 0; sx < IMG_H; sx++)
		for (int sy = 0; sy < IMG_H; sy++)
			my_mlx_pixel_put(&(mlx()->img), sx,  sy, 0);
}

void	create_square(t_object *obj, int color)
{

	obj->img.img = mlx_new_image(mlx()->mlx, GRID, GRID);
	obj->img.w = GRID;
	obj->img.h = GRID;	
	obj->img.addr = mlx_get_data_addr(obj->img.img, \
	&obj->img.bits_per_pixel, &obj->img.line_length, &obj->img.endian);
	for (int x = 0; x < GRID; x++)
		for (int y = 0; y < GRID; y++)
			my_mlx_pixel_put(&(obj->img), x, y, color);
}

