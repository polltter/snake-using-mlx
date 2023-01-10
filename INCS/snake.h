/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvenanci@student.42lisboa.com <mvenanci    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:53:21 by mvenanci@st       #+#    #+#             */
/*   Updated: 2023/01/10 21:06:40 by mvenanci@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE
# define SNAKE

# include <../mlx_linux/mlx.h>
# include <stdlib.h>

# define IMG_W 1000	
# define IMG_H 1000

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx_data {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
}	t_mlx_data;

#endif