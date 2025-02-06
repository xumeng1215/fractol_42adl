/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu <mexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:34:37 by mexu / Char       #+#    #+#             */
/*   Updated: 2025/02/06 14:39:54 by mexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// includes headers
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# ifdef __APPLE__
#  include "minilibx_mac/mlx.h"

enum {
	XK_w = 13,
	XK_a = 0,
	XK_s = 1,
	XK_d = 2,
	XK_Up = 126,
	XK_Down = 125,
	XK_Left = 123,
	XK_Right = 124,
	XK_space = 49,
	XK_Page_Up = 116,
	XK_Page_Down = 121,
	XK_r = 15,
	XK_Escape = 53,
	Button1 = 1,
	Button4 = 4,
	Button5 = 5,
	KeyPress = 2,
	KeyPressMask = (1L << 0),
	ButtonPress = 4,
	ButtonPressMask = (1L << 2),
	DestroyNotify = 17,
	StructureNotifyMask = (1L << 17)
};

# else
#  include "minilibx-linux/mlx.h"
#  include <X11/keysym.h>
#  include <X11/X.h>
# endif

// window size define
# define WIDTH 600
# define HEIGHT 600

// some colors
# define BLACK 0x000000 // RGB(0, 0, 0)
# define WHITE 0xFFFFFF // RGB(255, 255, 255)
# define RED 0xFF0000   // RGB(255, 0, 0)
# define GREEN 0x00FF00 // RGB(0, 255, 0)
# define BLUE 0x0000FF  // RGB(0, 0, 255)
# define YELLOW 0xFFFF00
# define MAGENTA_BURST 0xFF00FF
# define LIME_SHOCK 0xCCFF00
# define NEON_ORANGE 0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC
# define HOT_PINK 0xFF66B2
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

// struct define
// a complex number or a pair of double to present as range
typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	char			*name;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	unsigned int	iter_limit;
	t_complex		julia_k;
	double			escape_value;
	t_complex		shift;
	double			zoom;
	int				color_index;
	int				start_color;
	int				end_color;
}	t_fractol;

// function prototypes
int			check_args(int ac, char **av);

void		fractal_init(t_fractol *f);
void		fractal_render(t_fractol *f);
void		data_init(t_fractol *f);

// calculate the iteration numbers
int			calc_julia(t_fractol *f, t_complex z);
int			calc_mandelbrot(t_fractol *f, t_complex c);
int			calc_tricorn(t_fractol *f, t_complex c);

// event handlers
int			ft_exit(t_fractol *f);
int			key_handler(int keysym, t_fractol *f);
int			mouse_handler(int button, int x, int y, t_fractol *f);

// math utils
double		scale_map(double num, t_complex new_range, t_complex old_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		magnitude_squared(t_complex z);
t_complex	new_complex(double x, double y);

// string utils
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
double		ft_atodbl(char *s);

// color shift
void		color_shift(t_fractol *f);

// change julia set
void		julia_transfer(int x, int y, t_fractol *f);

#endif // fractol.h
