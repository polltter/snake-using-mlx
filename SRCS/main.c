/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 17:38:17 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/snake.h"



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


t_mlx_data *mlx(){

	static t_mlx_data data;

	return (&data);
}


int	handle_keys(int k, t_mlx_data *data)
{
	for (int i = 0; i < 5; i++)
	{
		if (mlx()->objs[i]->keys)
		{	
			data->this_obj = mlx()->objs[i]; 
			mlx()->objs[i]->keys(k);
		}
	}
	if (k != 'w' && k != 'a' && k != 's' && k != 'd' && k != 65307)
		return (1);	
	draw_rec(this()->pos.x, this()->pos.y, 0);
	if (k == 65307)
		ft_close(mlx());
	draw();
	return (1);
}

int up(t_mlx_data *data)
{
	t_object *t = data->this_obj;
	draw_clear();
	for (int i = 0; i < 5; i++)
	{
		data->this_obj = mlx()->objs[i]; 
		mlx()->objs[i]->render();
	}
	draw();
	data->this_obj = t;
	return (1);
}

int main(void)
{
	
	data_init(mlx());
	mlx_hook(mlx()->mlx_win, 17, 0, ft_close, mlx());
	for (int i = 0; i < 5; i++)
	{
		if (i > 0)
		{
			mlx()->objs[i] = new_object(i * GRID, i * GRID, sizeof(t_object));		
			create_square(mlx()->objs[i], 345678 * (i + 1));
		}
		else 
			mlx()->objs[i] =  new_apple(i * GRID, i * GRID);
	}
	mlx()->this_obj = mlx()->objs[0];
	mlx_hook(mlx()->mlx_win, 2, 1l << 0, handle_keys, mlx());
	//mlx_hook(mlx()->mlx_win, 4, 1l << 2, select_obj, mlx());
	mlx_loop_hook(mlx()->mlx, up, mlx());
	mlx_loop(mlx()->mlx);
}