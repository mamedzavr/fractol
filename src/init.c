/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:58:07 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/03/29 21:37:15 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		setmove(t_fractol *f)
{
	f->move[0].movex = 0;
	f->move[0].movey = 0;
	f->move[0].zoom = 1;
	f->move[1].movex = 0;
	f->move[1].movey = 0;
	f->move[1].zoom = 1;
	f->move[2].movex = 0;
	f->move[2].movey = 0;
	f->move[2].zoom = 1;
}

t_fractol		*init(void)
{
	t_fractol	*f;

	if (!(f = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		return (NULL);
	f->ptr = mlx_init();
	f->win = mlx_new_window(f->ptr, W, H, "fractol");
	f->iter = 50;
	f->c[0].cre = -0.7;
	f->c[0].cim = -0.3;
	f->c[2].cre = 0.5;
	f->c[2].cim = 0;
	f->c[2].maxre = 2;
	f->c[2].minre = -2;
	f->c[2].maxim = 2;
	f->c[2].minim = -2;
	f->img.img_ptr = mlx_new_image(f->ptr, W, H);
	f->img.data = (int *)mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
	&f->img.size_l, &f->img.endian);
	f->color.r = 50;
	f->color.g = 100;
	f->color.b = 150;
	setmove(f);
	f->mouse.press = 0;
	return (f);
}
