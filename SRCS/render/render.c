/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:07:48 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/13 00:22:29 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCS/snake.h"

void	render_each(t_elems *e, void *o)
{
	t_object	*value;
	
	(void)o;
	value = e->content;
	mlx()->this_obj = value;
	value->render();
}

void	keys_each(t_elems *e, void *o)
{
	t_object	*value;
	
	(void)o;
	value = e->content;
	mlx()->this_obj = value;
	if (value->keys)
		value->keys((*(int *)o));
}