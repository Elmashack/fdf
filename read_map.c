/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 21:47:50 by elman             #+#    #+#             */
/*   Updated: 2021/09/10 13:52:58 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit (0);
	line = get_next_line(fd);
	width = ft_cha_num_in_str(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	z_alloc(t_struct *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (data->z_matrix == NULL)
		return ;
	i = 0;
	while (i <= data->height)
	{
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
		if (data->z_matrix == NULL)
			return ;
	}
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_split(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

int	read_map(char *file_name, t_struct *data)
{
	int		i;
	char	*line;
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (0);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	z_alloc(data);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[++i] = NULL;
	return (0);
}
