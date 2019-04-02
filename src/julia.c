/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:00:10 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 17:43:40 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		crunch(t_fractol *f)
{
	int		i;

	f->c[0].newre = (f->x - W / 2) / (0.3 * f->move[0].zoom * W) +
	f->move[0].movex;
	f->c[0].newim = (f->y - H / 2) / (0.3 * f->move[0].zoom * H) +
	f->move[0].movey;
	i = -1;
	while ((f->c[0].newre * f->c[0].newre + f->c[0].newim * f->c[0].newim)
												< 4 && ++i < f->iter[0])
	{
		f->c[0].oldre = f->c[0].newre;
		f->c[0].oldim = f->c[0].newim;
		f->c[0].newre = f->c[0].oldre * f->c[0].oldre - f->c[0].oldim *
		f->c[0].oldim + f->c[0].cre;
		f->c[0].newim = 2 * f->c[0].oldre * f->c[0].oldim + f->c[0].cim;
	}
	if (i != f->iter[0])
		f->img.data[f->y * W + f->x] = ((i * f->color.r) % 255 << 16) +
		((i * f->color.g) % 255 << 8) + ((i * f->color.b) % 255);
	else
		f->img.data[f->y * W + f->x] = 0;
}

static	void	*julia_alg(void *fra)
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

void			julia(t_fractol *f)
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
		pthread_create(&t[i], NULL, julia_alg, &fr[i]);
	}
	while (i--)
		pthread_join(t[i], NULL);
}
