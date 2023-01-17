//
// Created by mvenanci on 1/16/23.
//
#include "../../INCS/snake.h"

int collision(t_object *a, t_object *b)
{
    return (!(a->pos.x < b->pos.x + b->pos.w && \
        a->pos.x + a->pos.w > b->pos.x && \
        a->pos.y < b->pos.y + b->pos.h && \
        a->pos.y + a->pos.h > b->pos.y));
}
void collision_each(t_elems *elem, void *snake)
{
    t_object *obj = (t_object *)elem->content;
    mlx()->this_obj = obj;
    if (obj !=  snake && !collision((t_object *)snake, obj))
    {
        if (obj->collided)
            obj->collided((t_object *)snake);
        mlx()->this_obj = snake;
        ((t_object *)snake)->collided(obj);
    }
}
