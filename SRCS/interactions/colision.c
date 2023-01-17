//
// Created by mvenanci on 1/16/23.
//
#include "../../INCS/snake.h"

int collision(t_object *a, t_object *b)
{
    if (a->pos.x <= b->pos.x + GRID && a->pos.x >= b->pos.x \
        && a->pos.y <= b->pos.y + GRID && a->pos.y >= b->pos.y)
        return (0);
    else if (a->pos.x <= b->pos.x + GRID && a->pos.x >= b->pos.x \
        && a->pos.y + GRID <= b->pos.y + GRID && a->pos.y + GRID >= b->pos.y)
        return (0);
    else if (a->pos.x + GRID <= b->pos.x + GRID && a->pos.x + GRID >= b->pos.x \
        && a->pos.y <= b->pos.y + GRID && a->pos.y >= b->pos.y)
        return (0);
    else if (a->pos.x + GRID <= b->pos.x + GRID && a->pos.x + GRID >= b->pos.x \
        && a->pos.y + GRID <= b->pos.y + GRID && a->pos.y + GRID >= b->pos.y)
        return (0);
    return (1);
}
void collision_each(t_elems *elem, void *apple)
{
    t_object *obj = (t_object *)elem->content;
    if (obj !=  apple && !collision((t_object *)apple, obj))
        exit (0);

}
