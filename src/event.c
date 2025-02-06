/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <mexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 10:31:32 by mexu / Char       #+#    #+#             */
/*   Updated: 2025/02/06 14:23:35 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// exit program when press ESC or the x button


#ifdef __APPLE__
    // Exit function for macOS
    int ft_exit(t_fractol *f)
    {
        mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
        mlx_destroy_window(f->mlx_ptr, f->win_ptr);
        exit(EXIT_SUCCESS);
    }

#else
    // Exit function for Linux
    int ft_exit(t_fractol *f)
    {
        mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
        mlx_destroy_window(f->mlx_ptr, f->win_ptr);
        mlx_destroy_display(f->mlx_ptr); // Specific to Linux
        free(f->mlx_ptr); // Freeing the mlx_ptr to prevent memory leaks
        exit(EXIT_SUCCESS);
    }
#endif



// press ESC will exit the program
// press arrow keys or wsad to move the fractal
// page up and down to increase the iteration limits 
// space to change color
// press r to reset the fractal
int	key_handler(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		ft_exit(f);
	if (keysym == XK_Left || keysym == XK_a)
		f->shift.x += (0.25 * f->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		f->shift.x -= (0.25 * f->zoom);
	else if (keysym == XK_Up || keysym == XK_w)
		f->shift.y -= (0.25 * f->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		f->shift.y += (0.25 * f->zoom);
	else if (keysym == XK_Page_Up)
		f->iter_limit += 5;
	else if (keysym == XK_Page_Down && f->iter_limit > 5)
		f->iter_limit -= 5;
	else if (keysym == XK_space)
		color_shift(f);
	else if (keysym == XK_r)
		data_init(f);
	fractal_render(f);
	return (0);
}

// zoom in and out by the mouse wheel and adjust the shift values accordingly
// press left button will pick up the mouse position
// and transfer to a new julia set
int	mouse_handler(int button, int x, int y, t_fractol *f)
{
	if (button == Button5)
	{
		f->shift.x -= (f->zoom * scale_map(x, new_complex(-2, 2),
					new_complex(0, WIDTH)) * 0.1);
		f->shift.y -= (f->zoom * scale_map(y, new_complex(2, -2),
					new_complex(0, HEIGHT)) * 0.1);
		f->zoom *= 1.05;
	}
	else if (button == Button4)
	{
		f->shift.x += (f->zoom * scale_map(x, new_complex(-2, 2),
					new_complex(0, WIDTH)) * 0.1);
		f->shift.y += (f->zoom * scale_map(y, new_complex(2, -2),
					new_complex(0, HEIGHT)) * 0.1);
		f->zoom *= 0.95;
	}
	else if (button == Button1 && !ft_strncmp(f->name, "julia", 5))
		julia_transfer(x, y, f);
	fractal_render(f);
	return (0);
}
