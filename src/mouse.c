/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 11:53:53 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/03/29 21:32:16 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		deal_mouse(int x, int y, t_fractol *f)
{
	f->mouse.oldx = f->mouse.x;
	f->mouse.oldy = f->mouse.y;
	f->mouse.x = x;
	f->mouse.y = y;
	if (f->stopkey == 0 && x > f->mouse.oldx)
		f->c[f->frac].cre += 0.05;
	else if (f->stopkey == 0 && x < f->mouse.oldx)
		f->c[f->frac].cre -= 0.05;
	else if (f->stopkey == 0 && y > f->mouse.oldy)
		f->c[f->frac].cim += 0.05;
	else if (f->stopkey == 0 && y < f->mouse.oldy)
		f->c[f->frac].cim -= 0.05;
	draw(f);
	return (0);
}
