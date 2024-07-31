/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:37:49 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/07/04 11:26:58 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// function will be called when press a certain key
// the start color with change through this color choices list
// by calculating the color index
// the end color will always be black for now
void	color_shift(t_fractol *f)
{
	static int	colors_choice[13] = {
		WHITE, RED, BLUE, GREEN, YELLOW, MAGENTA_BURST,
		LIME_SHOCK, NEON_ORANGE, PSYCHEDELIC_PURPLE,
		AQUA_DREAM, HOT_PINK, ELECTRIC_BLUE, LAVA_RED};

	f->color_index = (f->color_index + 1) % 13;
	f->start_color = colors_choice[f->color_index];
}

// reset the julia k value according to x and y
// x and y will be the position of the mouse
void	julia_transfer(int x, int y, t_fractol *f)
{
	f->julia_k.x = scale_map(x, new_complex(-2, 2), new_complex(0, WIDTH))
		* f->zoom + f->shift.x;
	f->julia_k.y = scale_map(y, new_complex(2, -2), new_complex(0, HEIGHT))
		* f->zoom + f->shift.y;
}
