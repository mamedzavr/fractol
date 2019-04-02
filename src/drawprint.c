/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 15:18:29 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 17:43:01 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			draw(t_fractol *f)
{
	if (f->frac == 0)
	{
		julia(f);
		mlx_string_put(f->ptr, f->win, 200, 120, 0xFF, "Julia");
	}
	else if (f->frac == 1)
	{
		mandelbrot(f);
		mlx_string_put(f->ptr, f->win, 200, 120, 0xFF00, "Mandelbrot");
	}
	else if (f->frac == 2)
	{
		biomorph(f);
		mlx_string_put(f->ptr, f->win, 200, 120, 0xFF0000, "Biomorph");
	}
	print(f);
}

static void		allocatanddel(t_fractol *f)
{
	char	*p[5];
	int		i;

	i = -1;
	p[0] = ft_itoa(f->move[f->frac].zoomfactor);
	p[1] = ft_itoa(f->iter[f->frac]);
	p[2] = ft_itoa(f->color.r);
	p[3] = ft_itoa(f->color.g);
	p[4] = ft_itoa(f->color.b);
	mlx_string_put(f->ptr, f->win, 200, 20, 0xFFFFFF, p[0]);
	mlx_string_put(f->ptr, f->win, 200, 80, 0xFFFFFF, p[1]);
	mlx_string_put(f->ptr, f->win, 0, 160, 0xFF0000, p[2]);
	mlx_string_put(f->ptr, f->win, 100, 160, 0xFF00, p[3]);
	mlx_string_put(f->ptr, f->win, 220, 160, 0xFF, p[4]);
	while (++i < 5)
		ft_strdel(&p[i]);
}

void			print(t_fractol *f)
{
	mlx_clear_window(f->ptr, f->win);
	mlx_put_image_to_window(f->ptr, f->win, f->img.img_ptr, 0, 0);
	mlx_string_put(f->ptr, f->win, 0, 0, 0xFFFFFF, "move: arrows");
	mlx_string_put(f->ptr, f->win, 0, 20, 0xFFFFFF, "zoom: - +");
	mlx_string_put(f->ptr, f->win, 0, 40, 0xFFFFFF, "Im: < >");
	mlx_string_put(f->ptr, f->win, 0, 60, 0xFFFFFF, "Re: [ ]");
	mlx_string_put(f->ptr, f->win, 0, 80, 0xFFFFFF, "iterations: + -");
	mlx_string_put(f->ptr, f->win, 0, 100, 0xFFFFFF,
		"choose fractol: 1 || 2 || 3");
	mlx_string_put(f->ptr, f->win, 0, 120, 0xFFFFFF, "current fractol:");
	mlx_string_put(f->ptr, f->win, 0, 140, 0xFF0000, "Red: 1/4");
	mlx_string_put(f->ptr, f->win, 100, 140, 0xFF00, "Green: 2/5");
	mlx_string_put(f->ptr, f->win, 220, 140, 0xFF, "Blue: 3/6");
	allocatanddel(f);
}
