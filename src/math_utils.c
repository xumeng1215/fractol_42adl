/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:26:55 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/07/04 10:53:01 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

//set up complex number or a pair of doubles
t_complex	new_complex(double x, double y)
{
	t_complex	z;

	z.x = x;
	z.y = y;
	return (z);
}

// scale down or up with numbers range 
double	scale_map(double num, t_complex new_range, t_complex old_range)
{
	return ((new_range.y - new_range.x)
		/ (old_range.y - old_range.x)
		* (num - old_range.x) + new_range.x);
}

// return the sum of two complex numbers
t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	z;

	z.x = z1.x + z2.x;
	z.y = z1.y + z2.y;
	return (z);
}

// return the square of a complex number z
t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}

// return the squared magnitude of complex number z
double	magnitude_squared(t_complex z)
{
	return (z.x * z.x + z.y * z.y);
}
