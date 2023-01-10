/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/10 21:08:04 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/snake.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	data_init(t_mlx_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, IMG_W, IMG_H, "Snake!");
	data->img.img = mlx_new_image(data->mlx, IMG_W, IMG_H);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
}

int	ft_close(t_mlx_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

void draw(t_mlx_data *data)
{
	int x = 0;
	int y = 0;

	while (x <= IMG_W)
	{
		while (y <= IMG_H)
		{
			my_mlx_pixel_put(&(data->img), x, y, 0);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, (data->img).img, 0, 0);
}

/* int	handle_keys(int k, t_mlx_data *data)
{
	if (keycode == 65361)
		data->offset = sum_imaginary(data->offset, init_number(100, 0));
	else if (keycode == 65363)
		data->offset = sum_imaginary(data->offset, init_number(-100, 0));
	else if (keycode == 65362)
		data->offset = sum_imaginary(data->offset, init_number(0, 100));
	else if (keycode == 65364)
		data->offset = sum_imaginary(data->offset, init_number(0, -100));
	else if (keycode == 65307)
		ft_close(0);
	return (1);
} */

int main(void)
{
	t_mlx_data data;
	
	data_init(&data);
	mlx_hook(data.mlx_win, 17, 0, ft_close, &data);
	draw(&data);
	// mlx_hook(data.mlx_win, 2, 1l << 0, handle_keys, &data);
	mlx_loop(data.mlx);
}