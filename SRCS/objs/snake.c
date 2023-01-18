//
// Created by mvenanci on 1/17/23.
//

#include "../../INCS/snake.h"

t_data *body_img(void)
{
    static t_data body_img;
    return (&body_img);
}

void    add_new_body(t_body *body, t_snake *head)
{
    t_body *new;

    new = ft_calloc(sizeof(t_body));
    new->img = body_img();
    new->pos.h = head->pos.h;
    new->pos.w = head->pos.w;
    if (!body)
    {
        new->head = head;
        new->pos.x = head->pos.x - head->direction.x * GRID;
        new->pos.y = head->pos.y - head->direction.y * GRID;
        new->dir.x = head->direction.x;
        new->dir.y = head->direction.y;
        head->body = new;
    }
    else
    {
        head->tail->next = new;
        new->prev = head->tail;
        new->pos.x = head->tail->pos.x - head->tail->dir.x * GRID;
        new->pos.y = head->tail->pos.y - head->tail->dir.y * GRID;
        new->dir.x = head->tail->dir.x;
        new->dir.y = head->tail->dir.y;
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
        add_new_body(((t_snake *) this())->tail, (t_snake *) this());
}

static void update_pos(t_snake *snake)
{
    t_body *temp = snake->body;
    t_pos   temp_pos;
    t_pos   temp2_pos;

    static int count;

    if (count++ > 7)
    {
        temp_pos = snake->pos;
        if (snake->direction.y == 1)
            snake->pos.y -= 2;
        else if (snake->direction.y == -1)
            snake->pos.y += 2;
        else if (snake->direction.x == -1)
            snake->pos.x -= 2;
        else if (snake->direction.x == 1)
            snake->pos.x += 2;
        while (temp)
        {
            temp2_pos = temp->pos;
            temp->pos.x = temp_pos.x;
            temp->pos.y = temp_pos.y;
            temp_pos = temp2_pos;
            temp = temp->next;
        }
//        if (temp)
//        {
//            temp->pos.x = snake->pos.x - GRID * snake->direction.x;
//            temp->pos.y = snake->pos.y + GRID * snake->direction.y;
//            temp->dir.x = snake->direction.x;
//            temp->dir.y = snake->direction.y;
//        }

        count = 0;


    }
}

static void draw_snake(t_body *body)
{

    t_body  *temp = body;
    while (temp)
    {
        draw_img(temp->img, temp->pos);
        temp = temp->next;
    }
    draw_obj(this());
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