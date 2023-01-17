//
// Created by mvenanci on 1/17/23.
//

#include "../../INCS/snake.h"

static void collided(t_object *with)
{
    if (with->type == WALL)
    {
        printf("Morreu\n");
        exit(0);
    }
    else if (with->type == APPLE)
    {
        if ()
    }
}

static void render(void)
{
    t_apple *apple = (t_apple *) this();
    static int count;

    if (count++ > 3)
    {
		if (apple->direction == UP)
			apple->pos.y -= 2;
		else if (apple->direction == DOWN)
			apple->pos.y += 2;
		else if (apple->direction == LEFT)
			apple->pos.x -= 2;
		else if (apple->direction == RIGHT)
			apple->pos.x += 2;
        count = 0;
    }
    draw_obj(this());

}

static void move(int k)
{
    t_snake *snake = (t_snake *)this();
    if (k == 'w' && snake->direction != UP)
        snake->direction = UP;
    else if (k == 'a' && snake->direction != LEFT)
        snake->direction = LEFT;
    else if (k == 'd' && snake->direction != RIGHT)
        snake->direction = RIGHT;
    else if (k == 's'&& snake->direction != DOWN)
        snake->direction = DOWN;
}

t_object *new_snake(void)
{
    t_snake	*snake;
    t_pos	pos;
    t_body  *body = 0;
    pos.x = IMG_W / 2;
    pos.y = IMG_H / 2;
    snake = (t_snake *) new_object(pos, sizeof(t_snake));
    snake->type = SNAKE;
    load_imgs((t_object *) snake, "imgs/cona.xpm");
    snake->pos.w = snake->img.w;
    snake->pos.h = snake->img.h;
    snake->render = render;
    snake->keys = move;
    snake->collided = collided;
    snake->direction = RIGHT;
    return ((t_object *) snake);
}