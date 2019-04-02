/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:58:07 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 17:53:28 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		setmove(t_fractol *f)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		f->move[i].movex = 0;
		f->move[i].movey = 0;
		f->move[i].zoom = 1;
		f->iter[i] = 50;
	}
	f->c[0].cre = -0.7;
	f->c[0].cim = -0.3;
	f->c[2].cre = 0.5;
	f->c[2].cim = 0;
	f->c[2].maxre = 2;
	f->c[2].minre = -2;
	f->c[2].maxim = 2;
	f->c[2].minim = -2;
}

t_fractol		*init(char *argc)
{
	t_fractol	*f;

	if (!(f = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (NULL);
	if (ft_strcmp(argc, "julia") == 0)
		f->frac = 0;
	else if (ft_strcmp(argc, "mandelbrot") == 0)
		f->frac = 1;
	else if (ft_strcmp(argc, "biomorph") == 0)
		f->frac = 2;
	else
		error("Usage ./fractol name\nfractals:\njulia\nmandelbrot");
	f->ptr = mlx_init();
	f->win = mlx_new_window(f->ptr, W, H, "fractol");
	f->img.img_ptr = mlx_new_image(f->ptr, W, H);
	f->img.data = (int *)mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
	&f->img.size_l, &f->img.endian);
	f->color.r = 5;
	f->color.g = 10;
	f->color.b = 15;
	setmove(f);
	f->mouse.press = 0;
	return (f);
}
