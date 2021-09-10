/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:21:49 by elman             #+#    #+#             */
/*   Updated: 2021/09/10 20:11:25 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_struct *data)
{
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 13)
		data->degree_cos += 0.1;
	if (key == 1)
		data->degree_cos -= 0.1;
	if (key == 2)
		data->degree_sin += 0.1;
	if (key == 0)
		data->degree_sin -= 0.1;
	if (key == 53)
		exit(0);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_struct	*data;

	data = (t_struct *)malloc(sizeof(t_struct));
	if (data == NULL)
		return (0);
	if (argc < 2)
		return (0);
	read_map(argv[1], data);
	data->shift_x = 150;
	data->shift_y = 150;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 20;
	data->degree_cos = 0.8;
	data->degree_sin = 0.8;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
