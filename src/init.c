/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:00:32 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/07/04 11:39:06 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// output error msg when set up
void	malloc_error(void)
{
	ft_putstr_fd("Problem with malloc\n", STDOUT_FILENO);
	exit(EXIT_FAILURE);
}

// reset the t_fractol f to default value
// will be called when press key r
void	data_init(t_fractol *f)
{
	f->escape_value = 4;
	f->iter_limit = 40;
	f->shift.x = 0.0;
	f->shift.y = 0.0;
	f->zoom = 1.0;
	f->color_index = 0;
	f->start_color = WHITE;
	f->end_color = BLACK;
}

// hook event
static void	event_init(t_fractol *f)
{
	mlx_hook(f->win_ptr, KeyPress, KeyPressMask, key_handler, f);
	mlx_hook(f->win_ptr, ButtonPress, ButtonPressMask, mouse_handler, f);
	mlx_hook(f->win_ptr, DestroyNotify, StructureNotifyMask, ft_exit, f);
}

// set up mlx pointer, window pointer, image
// void	fractal_init(t_fractol *f)
// {
// 	f->mlx_ptr = mlx_init();
// 	if (NULL == f->mlx_ptr)
// 		malloc_error();
// 	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->name);
// 	if (NULL == f->win_ptr)
// 	{
// 		// mlx_destroy_display(f->mlx_ptr);
// 		free(f->mlx_ptr);
// 		malloc_error();
// 	}
// 	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
// 	if (NULL == f->img.img_ptr)
// 	{
// 		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
// 		// mlx_destroy_display(f->mlx_ptr);
// 		free(f->mlx_ptr);
// 		malloc_error();
// 	}
// 	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr,
// 			&f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
// 	event_init(f);
// 	data_init(f);
// }
void	fractal_init(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if (NULL == f->mlx_ptr)
		malloc_error();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->name);
	if (NULL == f->win_ptr)
	{
		free(f->mlx_ptr);
		malloc_error();
	}
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (NULL == f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		free(f->mlx_ptr);
		malloc_error();
	}
	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr,
			&f->img.bits_per_pixel, &f->img.line_length, &f->img.endian);
	event_init(f);
	data_init(f);
}
