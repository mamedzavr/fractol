/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 22:07:56 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/03/29 22:08:24 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		zero(t_fractol *f)
{
	f->c[1].newre = 0;
	f->c[1].oldre = 0;
	f->c[1].newim = 0;
	f->c[1].oldim = 0;
}

static void		crunch(t_fractol *f)
{
	int		i;

	f->c[1].cre = (f->x - W / 2) / (0.3 * f->move[1].zoom * W) +
		f->move[1].movex;
	f->c[1].cim = (f->y - H / 2) / (0.3 * f->move[1].zoom * H) +
		f->move[1].movey;
	zero(f);
	i = -1;
	while ((f->c[1].newre * f->c[1].newre + f->c[1].newim * f->c[1].newim)
	< 4 && ++i < f->iter)
	{
		f->c[1].oldre = f->c[1].newre;
		f->c[1].oldim = f->c[1].newim;
		f->c[1].newre = f->c[1].oldre * f->c[1].oldre - f->c[1].oldim *
			f->c[1].oldim + f->c[1].cre;
		f->c[1].newim = 2 * f->c[1].oldre * f->c[1].oldim + f->c[1].cim;
	}
	if (i != f->iter)
		f->img.data[f->y * W + f->x] = ((i * f->color.r) % 255 << 16) +
		((i * f->color.g) % 255 << 8) + ((i * f->color.b) % 255);
	else
		f->img.data[f->y * W + f->x] = 0;
}

static void		*burningship_alg(void *fra)
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
			crunch(f);
			f->y++;
		}
	}
	return (fra);
}

void			burningship(t_fractol *f)
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
		pthread_create(&t[i], NULL, burningship_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
}
