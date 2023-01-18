//
// Created by mvenanci on 1/17/23.
//

#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct s_object t_object;
typedef struct s_apple t_apple;
typedef struct s_snake t_snake;
typedef struct s_pos t_pos;
typedef struct s_body t_body;

typedef enum e_type{
    OBJECT,
    APPLE,
    WALL,
    SNAKE
}	t_type;

typedef enum e_dir{
    UP,
    DOWN,
    LEFT,
    RIGHT
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
    void		*objs;
}	t_mlx_data;

struct s_pos {
    int	x;
    int	y;
    float w;
    float h;
};

struct s_object {
    t_type	type;
    t_data	img;
    t_pos	pos;
    void	(*update)();
    void	(*render)();
    void    (*collided)(t_object *obj);
    void	(*keys)(int k);
};

struct s_apple {
    t_type	type;
    t_data	img;
    t_pos	pos;
    void	(*update)();
    void	(*render)();
    void    (*collided)(t_object *obj);
    void	(*keys)(int k);
    int		direction;
};

struct s_body{
    t_data  *img;
    t_pos   pos;
    t_body  *next;
    t_body  *prev;
    t_snake *head;
};

struct s_snake {
    t_type	type;
    t_data	img;
    t_pos	pos;
    void	(*update)();
    void	(*render)();
    void    (*collided)(t_object *obj);
    void	(*keys)(int k);
    t_pos   direction;
    t_body  *body;
    t_body  *tail;
};

#endif //SNAKE_OBJECTS_H
