/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 10:50:22 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 17:48:46 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		deal_zoom(int key, int x, int y, t_fractol *f)
{
	if (key == 4 && f->move[f->frac].zoomfactor < 300)
	{
		f->move[f->frac].zoom *= pow(1.05, 2);
		f->move[f->frac].movey += ((y - H / 2) /
			(3500.0 * f->move[f->frac].zoom));
		f->move[f->frac].movex += ((x - W / 2) /
			(3500.0 * f->move[f->frac].zoom));
		f->move[f->frac].zoomfactor++;
		if (f->move[f->frac].zoomfactor % 50 == 0)
			f->iter[f->frac] += 25;
	}
	else if (key == 5 && f->move[f->frac].zoomfactor > 0)
	{
		f->move[f->frac].zoom /= pow(1.05, 2);
		f->move[f->frac].movey -= ((y - H / 2) /
			(3500.0 * f->move[f->frac].zoom));
		f->move[f->frac].movex -= ((x - W / 2) /
			(3500.0 * f->move[f->frac].zoom));
		f->move[f->frac].zoomfactor--;
		if (f->move[f->frac].zoomfactor % 50 == 0 && f->iter[f->frac] > 25)
			f->iter[f->frac] -= 25;
	}
	draw(f);
	return (0);
}
