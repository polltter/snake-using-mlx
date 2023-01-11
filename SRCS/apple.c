/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 16:52:01 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 17:40:40 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/snake.h"


static void render(void)
{
	t_apple *apple = (t_apple *) this();
	static int count;
	if (count++ > 50)	
	{	
		if (apple->direction == UP)
			apple->pos.y -= 10;
		else if (apple->direction == DOWN)
			apple->pos.y += 10;
		else if (apple->direction == LEFT)
			apple->pos.x -= 10;
		else if (apple->direction == RIGTH)
			apple->pos.x += 10;			
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
		apple->direction = RIGTH;
	else if (k == 's')
		apple->direction = DOWN;
}

t_object *new_apple(int x, int y)
{
	t_apple	*apple;
	apple = (t_apple *) new_object(x, y, sizeof(t_apple));
	apple->type = APPLE;
	load_imgs((t_object *) apple, "imgs/cona.xpm");
	apple->render = render;
	apple->keys = move;
	apple->direction = RIGTH;
	return ((t_object *) apple);
}