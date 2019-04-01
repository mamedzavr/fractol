/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biomorph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:37:25 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/03/29 21:34:12 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		crunch(t_fractol *f)
{
	int			i;
	double		oldre2;
	double		oldim2;

	i = -1;
	while (!(fabs(f->c[2].oldre) > 10 || fabs(f->c[2].oldim) > 10 ||
	f->c[2].oldre * f->c[2].oldre + f->c[2].oldim * f->c[2].oldim > 100)
	&& ++i < f->iter)
	{
		oldre2 = f->c[2].oldre * (f->c[2].oldre * f->c[2].oldre - 3 *
			f->c[2].oldim * f->c[2].oldim) + f->c[2].cre;
		oldim2 = f->c[2].oldim * (3 * f->c[2].oldre * f->c[2].oldre -
			f->c[2].oldim * f->c[2].oldim) + f->c[2].cim;
		f->c[2].oldre = oldre2;
		f->c[2].oldim = oldim2;
	}
	if (fabs(f->c[2].oldre) < 10 || fabs(f->c[2].oldim) < 10)
		f->img.data[f->y * W + f->x] = ((i * f->color.r) % 255 << 16) +
			((i * f->color.g) % 255 << 8) + ((i * f->color.b) % 255);
	else
		f->img.data[f->y * W + f->x] = 0x0000000;
}

static void		*biomorph_alg(void *fra)
{
	int			buff;
	t_fractol	*f;

	f = (t_fractol*)fra;
	f->x = -1;
	buff = f->y;
	while (++f->x < W)
	{
		f->y = buff;
		while (f->y < f->y1)
		{
			f->c[2].newre = (f->c[2].minre + (f->c[2].maxre - f->c[2].minre) *
			f->x / W) / (1.2 * f->move[2].zoom) + f->move[2].movex;
			f->c[2].newim = (-f->c[2].minim - (f->c[2].maxim - f->c[2].minim) *
			f->y / H) / (1.2 * f->move[2].zoom) - f->move[2].movey;
			f->c[2].oldre = f->c[2].newre;
			f->c[2].oldim = f->c[2].newim;
			crunch(f);
			f->y++;
		}
	}
	return (fra);
}

void			biomorph(t_fractol *f)
{
	int			i;
	pthread_t	t[THREAD];
	t_fractol	fr[THREAD];

	i = -1;
	while (++i < THREAD)
	{
		ft_memcpy((void*)&fr[i], (void*)f, sizeof(t_fractol));
		fr[i].y = THREAD_W * i;
		fr[i].y1 = THREAD_W * (i + 1);
		pthread_create(&t[i], NULL, biomorph_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
}
