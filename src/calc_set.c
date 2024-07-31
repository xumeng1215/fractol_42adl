/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 22:29:53 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/07/04 00:08:53 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// giving a certain complex number (mapping from the pixels in window)
// calculate how many iterations it take to escape the fractal set
// returned number will be used to set the color of that pixel

int	calc_julia(t_fractol *f, t_complex z)
{
	unsigned int	n;

	n = 0;
	while (n < f->iter_limit)
	{
		if (magnitude_squared(z) > f->escape_value)
			break ;
		z = sum_complex(square_complex(z), f->julia_k);
		n++;
	}
	return (n);
}

int	calc_mandelbrot(t_fractol *f, t_complex c)
{
	t_complex		z;
	unsigned int	n;

	z.x = 0;
	z.y = 0;
	n = 0;
	while (n < f->iter_limit)
	{
		if (magnitude_squared(z) > f->escape_value)
			break ;
		z = sum_complex(square_complex(z), c);
		n++;
	}
	return (n);
}

int	calc_tricorn(t_fractol *f, t_complex c)
{
	t_complex		z;
	t_complex		temp;
	unsigned int	n;

	z = c;
	n = 0;
	while (n < f->iter_limit)
	{
		if (magnitude_squared(z) > f->escape_value)
			break ;
		temp.x = z.x * z.x - z.y * z.y;
		temp.y = -2 * z.x * z.y;
		z = sum_complex(temp, c);
		n++;
	}
	return (n);
}
