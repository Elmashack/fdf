/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:07:05 by elman             #+#    #+#             */
/*   Updated: 2021/09/05 15:33:52 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct t_struct
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		c;
	int		shift_x;
	int		shift_y;
	float	degree_sin;
	float	degree_cos;
	float	x;
	float	y;
	void	*mlx_ptr;
	void	*win_ptr;

}		t_struct;
int		ft_cha_num_in_str(char const *s, char c);
void	algrth_bresen(float x1, float y1, t_struct *data);
int		read_map(char *file_name, t_struct *data);
void	draw(t_struct *data);
#endif