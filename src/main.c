/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:14:46 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 16:38:56 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
	return (0);
}

int		main(int ac, char **av)
{
	t_fractol	*f;

	if (!(ac == 2 || ac == 3))
		error("Usage ./fractol name\nfractals:\njulia\nmandelbrot\nbiomorph");
	f = init();
	f->stopkey = 0;
	if (ft_strcmp(av[1], "julia") == 0)
		f->frac = 0;
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		f->frac = 1;
	else if (ft_strcmp(av[1], "biomorph") == 0)
		f->frac = 2;
	else
		error("Usage ./fractol name\nfractals:\njulia\nmandelbrot");
	draw(f);
	mlx_hook(f->win, 17, 0, error, f);
	mlx_hook(f->win, 2, 0, deal_key, f);
	mlx_hook(f->win, 4, 0, deal_zoom, f);
	if (f->frac == 0 || f->frac == 2)
		mlx_hook(f->win, 6, 0, deal_mouse, f);
	mlx_loop(f->ptr);
	return (0);
}
