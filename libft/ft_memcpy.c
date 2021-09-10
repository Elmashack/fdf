/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:47:46 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 15:48:05 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t i)
{
	int	a;

	a = 0;
	if (!(char *)src && !(const char *)dst)
		return (NULL);
	while (i > 0)
	{
		((char *) dst)[a] = ((const char *) src)[a];
		a++;
		i--;
	}	
	return (dst);
}
