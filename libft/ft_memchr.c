/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marinamamedova <marinamamedova@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:46:11 by nluya             #+#    #+#             */
/*   Updated: 2021/05/20 21:35:55 by marinamamed      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memchr(const void *dst, int c, size_t i)
{
	int	a;

	a = (int)i;
	while (a > 0)
	{
		if (*(const unsigned char *)dst == (unsigned char)c)
			return ((char *)dst);
		dst++;
		a--;
	}	
	return (NULL);
}
