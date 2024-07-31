/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mexu / Charlie <charlie_xumeng@hotmail.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:38:59 by mexu / Char       #+#    #+#             */
/*   Updated: 2024/07/08 16:10:46 by mexu / Char      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	show_tips(void)
{
	ft_putstr_fd("./fractol julia <r> <i>\n", STDOUT_FILENO);
	ft_putstr_fd("./fractol mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd("./fractol tricorn\n", STDOUT_FILENO);
	ft_putstr_fd("WSAD and arrow keys to move the fractal.\n", STDOUT_FILENO);
	ft_putstr_fd("page up and down to adjust the iteration limits.\n", STDOUT_FILENO);
	ft_putstr_fd("space to change color, and r to reset.\n", STDOUT_FILENO);
}

int	check_args(int ac, char **av)
{
	if (4 == ac && !ft_strncmp(av[1], "julia", 5))
		return (1);
	else if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10))
		return (1);
	else if (2 == ac && !ft_strncmp(av[1], "tricorn", 7))
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (check_args(ac, av))
	{
		f.name = av[1];
		if (!ft_strncmp(f.name, "julia", 5))
		{
			f.julia_k.x = ft_atodbl(av[2]);
			f.julia_k.y = ft_atodbl(av[3]);
		}
		fractal_init(&f);
		fractal_render(&f);
		mlx_loop(f.mlx_ptr);
	}
	else
	{
		show_tips();
		exit(EXIT_FAILURE);
	}
}
