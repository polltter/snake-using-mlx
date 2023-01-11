/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:21:03 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/11 17:39:38 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCS/snake.h"

t_object *this(void)
{
	return (mlx()->this_obj);
}

static void render()
{
	draw_obj(this());
}

// static void move(int k) {

// 	if (k == 'w')
// 		this()->pos.y -= GRID;
// 	else if (k == 'a')
// 		this()->pos.x -= GRID;
// 	else if (k == 's')
// 		this()->pos.y += GRID;
// 	else if (k == 'd')
// 		this()->pos.x += GRID;
// }


t_object	*new_object(int x, int y, size_t size)
{
	t_object *new = calloc(size, 1);
	new->type = OBJECT;
	new->pos.x = x;
	new->pos.y = y;
	new->render = render;
	//new->keys = move;
	return (new);
}