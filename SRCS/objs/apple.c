/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:52:01 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/16 19:46:48 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/snake.h"

static void collided(t_object *with)
{
    (void)with;
    srand(time(0));
    this()->pos.x = (float)rand() / (float)RAND_MAX * (IMG_W - 105) + 35;
    this()->pos.y = (float)rand() / (float)RAND_MAX * (IMG_H - 105) + 35;
}


static void render(void)
{
	t_apple *apple = (t_apple *) this();
    static int count_2;
    static int flag;

    if (!flag && ++count_2 > 70)
    {
        apple->pos.w = 36;
        apple->pos.h = 36;
        flag = 1;
    }
    else if (++count_2 > 140)
    {
        flag = 0;
        count_2 = 0;
        apple->pos.w = 32;
        apple->pos.h = 32;
    }
	draw_obj(this());
}

static void move(int k) {

	t_apple *apple = (t_apple *)this();
	if (k == 'w' && apple->direction != UP)
		apple->direction = UP;
	else if (k == 'a' && apple->direction != LEFT)
		apple->direction = LEFT;
	else if (k == 'd' && apple->direction != RIGHT)
		apple->direction = RIGHT;
	else if (k == 's'&& apple->direction != DOWN)
		apple->direction = DOWN;
}

t_object *new_apple(void)
{
	t_apple	*apple;
	t_pos	pos;
    srand(time(0));
    pos.x = (float)rand() / (float)RAND_MAX * (IMG_W - 105) + 35;
	pos.y = (float)rand() / (float)RAND_MAX * (IMG_H - 105) + 35;
	apple = (t_apple *) new_object(pos, sizeof(t_apple));
	apple->type = APPLE;
	load_imgs((t_object *) apple, "imgs/cona.xpm");
    apple->pos.w = apple->img.w;
    apple->pos.h = apple->img.h;
	apple->render = render;
	apple->keys = move;
    apple->collided = collided;
	apple->direction = RIGHT;
	return ((t_object *) apple);
}