/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:53:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/16 19:38:20 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_H
# define SNAKE_H

# include <../mlx_linux/mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "objects.h"
# include "../SRCS/list_utils/list_utils.h" 

# define IMG_W 1000	
# define IMG_H 1000
# define GRID 32



t_object	*new_object(t_pos pos,size_t size);
void		draw();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_mlx_data *mlx();
void	    draw_obj(t_object *obj);
void	    create_square(t_object *obj, int color);
void	    draw_rec(int x, int y, int color);
void	    load_imgs(t_object *obj, char *path);
t_object    *this();
t_object    *new_apple(void);
void	    draw_clear();
void	    render_each(t_elems *e, void *o);
void	    keys_each(t_elems *e, void *o);
void	    create_rec(t_object *obj, int color, t_pos rec);
t_object    *new_wall(t_pos pos);
void        collision_each(t_elems *elem, void *apple);
void	    draw_img(t_data *data, t_pos pos);
t_object    *new_snake(void);
#endif