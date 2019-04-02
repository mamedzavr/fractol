/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:14:46 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 17:38:26 by wqarro-v         ###   ########.fr       */
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

	if (ac != 2)
		error("Usage ./fractol name\nfractals:\njulia\nmandelbrot\nbiomorph");
	f = init(av[1]);
	f->stopkey = 0;
	draw(f);
	mlx_hook(f->win, 17, 0, error, f);
	mlx_hook(f->win, 2, 0, deal_key, f);
	mlx_hook(f->win, 4, 0, deal_zoom, f);
	mlx_hook(f->win, 6, 0, deal_mouse, f);
	mlx_loop(f->ptr);
	return (0);
}
