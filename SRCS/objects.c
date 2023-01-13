/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:21:03 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 00:05:28 by mvenanci@st      ###   ########.fr       */
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

t_object	*new_object(int x, int y, size_t size)
{
	t_object *new = ft_calloc(size);
	new->type = OBJECT;
	new->pos.x = x;
	new->pos.y = y;
	new->render = render;
	return (new);
}