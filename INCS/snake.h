/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:53:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 17:36:26 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE
# define SNAKE

# include <../mlx_linux/mlx.h>
# include <stdlib.h>
# include <stdio.h>

# define IMG_W 1000	
# define IMG_H 1000
# define GRID 32

//typedef this_objs() this;

typedef struct s_object t_object;
typedef struct s_apple t_apple;
typedef struct s_pos t_pos;

typedef enum e_type{
	OBJECT,
	APPLE
}	t_type;

typedef enum e_dir{
	UP,
	DOWN,
	LEFT,
	RIGTH
}	t_dir;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int 	w;
	int		h;
}				t_data;

typedef struct s_mlx_data {
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_object	*this_obj;
	t_object	*objs[5];
}	t_mlx_data;

struct s_pos {
	int	x;
	int	y;
};

struct s_object {
	t_type	type;
	t_data	img;
	t_pos	pos;
	void	(*update)();
	void	(*render)();
	void	(*keys)(int k);
};

struct s_apple {
	t_type	type;
	t_data	img;
	t_pos	pos;
	void	(*update)();
	void	(*render)();
	void	(*keys)(int k);
	int		direction;
};

t_object	*new_object(int x, int y, size_t size);
void		draw();
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_mlx_data *mlx();
void	draw_obj(t_object *obj);
void	create_square(t_object *obj, int color);
void	draw_rec(int x, int y, int color);
void	load_imgs(t_object *obj, char *path);
t_object *this();
t_object *new_apple(int x, int y);
void	draw_clear();


#endif