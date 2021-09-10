/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:45:42 by nluya             #+#    #+#             */
/*   Updated: 2021/09/06 09:58:49 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
int	ft_atoi(char *str)
{
	int				neg;
	unsigned long	nb;
	unsigned long	a;

	a = 9223372036854775807;
	neg = 1;
	nb = 0;
	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	if (*str == '-')
		neg = neg * -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		nb = (nb * 10) + (*str - 48);
		str++;
		if (nb > a && neg > 0)
			return (-1);
		if (nb >= a && neg < 0)
			return (0);
	}
	return (nb * neg);
}
