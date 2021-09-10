/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 11:32:44 by nluya             #+#    #+#             */
/*   Updated: 2021/09/05 11:33:04 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_cha_num_in_str(char const *s, char c)
{
	size_t	num;
	char	check;

	check = 1;
	num = 0;
	while (*s)
	{
		if (*(s++) != c)
		{
			if (check)
				num++;
			check = 0;
		}
		else
			check = 1;
	}
	return (num);
}
