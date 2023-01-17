//
// Created by mvenanci on 1/16/23.
//
#include "../../INCS/snake.h"

static void render()
{
    draw_obj(this());
}

t_object *new_wall(t_pos pos)
{
    t_object    *wall;

    wall = (t_object *) new_object(pos, sizeof(t_object));
    wall->type = WALL;
    load_imgs((t_object *) wall, "imgs/wall.xpm");
    wall->pos.w = wall->img.w;
    wall->pos.h = wall->img.h;
    wall->render = render;
    return ((t_object *) wall);
}