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

#include "../INCS/snake.h"


static void render(void)
{
	t_apple *apple = (t_apple *) this();
	static int count;
	if (count++ > 4)
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

static void move(int k) {

	t_apple *apple = (t_apple *)this();
	if (k == 'w')
		apple->direction = UP;
	else if (k == 'a')
		apple->direction = LEFT;
	else if (k == 'd')
		apple->direction = RIGHT;
	else if (k == 's')
		apple->direction = DOWN;
}

t_object *new_apple(int x, int y)
{
	t_apple	*apple;
	t_pos	pos;
	pos.x = x;
	pos.y = y;
	apple = (t_apple *) new_object(pos, sizeof(t_apple));
	apple->type = APPLE;
	load_imgs((t_object *) apple, "imgs/cona.xpm");
	apple->render = render;
	apple->keys = move;
	apple->direction = RIGHT;
	return ((t_object *) apple);
}