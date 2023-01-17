/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:42:08 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/16 19:43:20 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/snake.h"

void	create_wall(void)
{
    t_pos   pos = {0, 0};

	for (; pos.x <= IMG_W; pos.x += 32)
		array(mlx()->objs)->add(new_wall(pos));
    for (pos.y=32, pos.x = IMG_W - GRID ; pos.y <= IMG_H; pos.y += 32)
        array(mlx()->objs)->add(new_wall(pos));
    for (pos.x = IMG_W - GRID,  pos.y = IMG_H - GRID; pos.x >= 0; pos.x -= 32)
        array(mlx()->objs)->add(new_wall(pos));
    for (pos.x = 0, pos.y = IMG_H - GRID; pos.y >= 0; pos.y -= 32)
        array(mlx()->objs)->add(new_wall(pos));
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


t_mlx_data *mlx(){

	static t_mlx_data data;

	return (&data);
}


int	handle_keys(int k)
{
	array(mlx()->objs)->for_each(keys_each, &k);
	if (k != 'w' && k != 'a' && k != 's' && k != 'd' && k != 65307)
		return (1);	
	if (k == 65307)
		ft_close(mlx());
	return (1);
}

int up(t_mlx_data *data)
{
	t_object *t = data->this_obj;
	draw_clear();
    array(mlx()->objs)->for_each(collision_each, array(mlx()->objs)->end->content);
	array(mlx()->objs)->for_each(render_each, NULL);
	draw();
	data->this_obj = t;
	return (1);
}

int main(void)
{
	data_init(mlx());
	mlx_hook(mlx()->mlx_win, 17, 0, ft_close, mlx());
	mlx()->objs = creat_array();
	create_wall();
	array(mlx()->objs)->add(new_apple(GRID + 1, GRID + 1));
	mlx_hook(mlx()->mlx_win, 2, 1l << 0, handle_keys, NULL);
	//mlx_hook(mlx()->mlx_win, 4, 1l << 2, select_obj, mlx());
	mlx_loop_hook(mlx()->mlx, up, mlx());
	mlx_loop(mlx()->mlx);
}