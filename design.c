/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:49:49 by nluya             #+#    #+#             */
/*   Updated: 2021/09/06 09:44:20 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs_max(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	else
		return (b);
}

void	isometric(float *x, float *y, int z, t_struct *data)
{
	*x = (*x - *y) * cos(data->degree_cos);
	*y = (*x + *y) * sin(data->degree_sin) - z;
}

void	isometric1(float *x1, float *y1, t_struct *data)
{
	int	z;
	int	z1;

	z = data->z_matrix[(int)data->y][(int)data->x];
	z1 = data->z_matrix[(int)*y1][(int)*x1];
	if (z || z1)
		data->c = 0xe80c0c;
	else
		data->c = 0xffffff;
	data->x *= data->zoom;
	data->y *= data->zoom;
	*x1 *= data->zoom;
	*y1 *= data->zoom;
	isometric(&data->x, &data->y, z, data);
	isometric(x1, y1, z1, data);
	data->x += data->shift_x;
	data->y += data->shift_y;
	*x1 += data->shift_x;
	*y1 += data->shift_y;
}

void	algrth_bresen(float x1, float y1, t_struct *data)
{
	float	x_step;
	float	y_step;
	int		max;

	isometric1(&x1, &y1, data);
	x_step = x1 - data->x;
	y_step = y1 - data->y;
	max = abs_max((int)x_step, (int)y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(data->x - x1) || (int)(data->y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->x, data->y, data->c);
		data->x += x_step;
		data->y += y_step;
	}
}

void	draw(t_struct *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
			{
				data->x = x;
				data->y = y;
				algrth_bresen((int)data->x + 1, (int)data->y, data);
			}
			if (y < data->height - 1)
			{
				data->x = x;
				data->y = y;
				algrth_bresen((int)data->x, (int)data->y + 1, data);
			}
			x++;
		}
		y++;
	}
}
