/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:18:55 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/07/04 11:39:06 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// set the pixel color
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

// fractal set calculation triage function
// will return the iteration numbers until z escape the fractal set
int	calc_iteration(t_fractol *f, t_complex z)
{
	int	iteration_number;

	if (!ft_strncmp(f->name, "julia", 5))
		iteration_number = calc_julia(f, z);
	else if (!ft_strncmp(f->name, "mandelbrot", 10))
		iteration_number = calc_mandelbrot(f, z);
	else
		iteration_number = calc_tricorn(f, z);
	return (iteration_number);
}

// loop through all the pixels inside of the window
// each pixel inside of the window will map to a complex number z
// pick color according to the iterations number until z escape the set
// then set the pixel's color
// after all the pixels' color are set (loop finished)
// then put the image to window
void	fractal_render(t_fractol *f)
{
	int			x;
	int			y;
	int			color;
	t_complex	z;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			z.x = (scale_map(x, new_complex(-2, 2), new_complex(0, WIDTH))
					* f->zoom) + f->shift.x;
			z.y = (scale_map(y, new_complex(2, -2), new_complex(0, HEIGHT))
					* f->zoom) + f->shift.y;
			color = scale_map(calc_iteration(f, z),
					new_complex(f->end_color, f->start_color),
					new_complex(0, f->iter_limit));
			my_pixel_put(x, y, &f->img, color);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
