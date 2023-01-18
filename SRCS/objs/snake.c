//
// Created by mvenanci on 1/17/23.
//

#include "../../INCS/snake.h"

t_data *body_img(void)
{
    static t_data *body_img;
    return (body_img);
}

void    add_new_body(t_body *body, t_snake *head)
{
    t_body *new;

    new = ft_calloc(sizeof(t_body));
    new->img = body_img();
    if (!body)
    {
        new->head = head;
        new->pos.x = head->pos.x - head->direction.x * GRID;
        new->pos.y = head->pos.y - head->direction.y * GRID;
        head->body = new;
    }
    else
    {
        head->tail->next = new;
        new->prev = head->tail;
        new->pos.x = head->pos.x - head->direction.x * GRID;
        new->pos.y = head->pos.y - head->direction.y * GRID;
    }
    head->tail = new;
}

static void collided(t_object *with)
{
    if (with->type == WALL)
    {
        printf("Morreu\n");
        exit(0);
    }
    else if (with->type == APPLE)
        array(mlx()->objs)->add(new_snake());
}

static void update_pos(t_snake *snake)
{
    t_body *temp = snake->tail;
    static int count;

    if (count++ > 3)
    {
        while (temp->head != snake)
        {
            temp->pos.x = temp->prev->pos.x;
            temp->pos.y = temp->prev->pos.y;
        }
        if (snake->direction.y == 1)
            snake->pos.y -= 2;
        else if (snake->direction.y == -1)
            snake->pos.y += 2;
        else if (snake->direction.x == -1)
            snake->pos.x -= 2;
        else if (snake->direction.x == 1)
            snake->pos.x += 2;
        count = 0;
    }
}

static void draw_snake(t_body *body)
{
    draw_obj(this());
    while (body)
    {
        draw_img(body->img, body->pos);
        body = body->next;
    }
}

static void render(void)
{
    update_pos((t_snake *)this());
    draw_snake(((t_snake *)this())->body);
}

static void move(int k)
{
    t_snake *snake = (t_snake *)this();
    if (k == 'w')
    {
        snake->direction.y = 1;
        snake->direction.x = 0;
    }
    else if (k == 'a')
    {
        snake->direction.x = -1;
        snake->direction.y = 0;
    }
    else if (k == 'd')
    {
        snake->direction.x = 1;
        snake->direction.y = 0;
    }
    else if (k == 's')
    {
        snake->direction.y = -1;
        snake->direction.x = 0;
    }
}

t_object *new_snake(void)
{
    t_snake	*snake;
    t_pos	pos;
    pos.x = IMG_W / 2;
    pos.y = IMG_H / 2;
    snake = (t_snake *) new_object(pos, sizeof(t_snake));
    snake->type = SNAKE;
    load_imgs((t_object *) snake, "imgs/cona.xpm");
    *body_img() = snake->img;
    snake->pos.w = snake->img.w;
    snake->pos.h = snake->img.h;
    snake->render = render;
    snake->keys = move;
    snake->collided = collided;
    snake->direction.x = 1;
    snake->body = 0;
    return ((t_object *) snake);
}