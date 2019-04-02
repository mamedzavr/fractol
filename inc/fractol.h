/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wqarro-v <wqarro-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 12:12:42 by wqarro-v          #+#    #+#             */
/*   Updated: 2019/04/01 17:40:53 by wqarro-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <pthread.h>
# include <OpenCL/opencl.h>

# define THREAD 60
# define THREAD_W 20
# define W 1200
# define H 1200

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
}				t_point;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mouse
{
	int			x;
	int			y;
	int			oldx;
	int			oldy;
	int			press;
}				t_mouse;

typedef struct	s_complex
{
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		minre;
	double		minim;
	double		maxre;
	double		maxim;
}				t_complex;

typedef struct	s_move
{
	double		movex;
	double		movey;
	double		zoom;
	int			zoomfactor;
}				t_move;

typedef struct	s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}				t_color;

typedef struct	s_fractol
{
	void		*win;
	void		*ptr;
	t_complex	c[3];
	t_move		move[3];
	t_mouse		mouse;
	t_img		img;
	t_color		color;
	int			frac;
	int			iter[3];
	int			stopkey;
	int			key;
	int			x;
	int			y;
	int			y1;
	int			buff;
}				t_fractol;

int				error(char *str);
t_fractol		*init(char	*argc);
int				deal_key(int key, t_fractol *f);
void			julia(t_fractol *f);
void			mandelbrot(t_fractol *f);
void			biomorph(t_fractol *f);
void			print(t_fractol *f);
void			draw(t_fractol *f);
int				deal_zoom(int key, int x, int y, t_fractol *f);
int				deal_mouse(int x, int y, t_fractol *f);

#endif
