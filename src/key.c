/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:38:52 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/03/29 21:34:00 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void		key3(int key, t_fractol *f)
{
	if (key == 86)
		f->color.r += 1;
	if (key == 87)
		f->color.g += 1;
	if (key == 88)
		f->color.b += 1;
	if (key == 83)
		f->color.r -= 1;
	if (key == 84)
		f->color.g -= 1;
	if (key == 85)
		f->color.b -= 1;
}

static void		key1(int key, t_fractol *f)
{
	if (key == 43)
		f->c[f->frac].cim += 0.01;
	if (key == 47)
		f->c[f->frac].cim -= 0.01;
	if (key == 30)
		f->c[f->frac].cre += 0.01;
	if (key == 33)
		f->c[f->frac].cre -= 0.01;
	if (key == 18)
		f->frac = 0;
	if (key == 19)
		f->frac = 1;
	if (key == 20)
		f->frac = 2;
}

static void		key0(int key, t_fractol *f)
{
	if (key == 125)
		f->move[f->frac].movey += 0.05;
	if (key == 126)
		f->move[f->frac].movey -= 0.05;
	if (key == 123)
		f->move[f->frac].movex -= 0.05;
	if (key == 124)
		f->move[f->frac].movex += 0.05;
	if (key == 69 && f->move[f->frac].zoomfactor < 300)
	{
		f->move[f->frac].zoom += 0.05;
		f->move[f->frac].zoomfactor++;
	}
	if (key == 78 && f->move[f->frac].zoomfactor > -10)
	{
		f->move[f->frac].zoom -= 0.05;
		f->move[f->frac].zoomfactor--;
	}
	if (key == 24)
		f->iter += 5;
	if (key == 27)
		f->iter -= 5;
}

int				deal_key(int key, t_fractol *f)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == 123 || key == 126 || key == 124 || key == 125 || key == 69 ||
	key == 78 || key == 69 || key == 78 || key == 24 || key == 27)
		key0(key, f);
	if (key == 43 || key == 47 || key == 33 || key == 30 || key == 18 ||
	key == 19 || key == 20 || key == 86 || key == 87 || key == 88)
		key1(key, f);
	if (key == 83 || key == 84 || key == 85 || key == 86 || key == 87 ||
	key == 88)
		key3(key, f);
	if (key == 49)
		f->stopkey ^= 1;
	f->key = key;
	draw(f);
	return (0);
}
