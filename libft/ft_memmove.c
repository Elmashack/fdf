/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 15:48:42 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 16:13:31 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*dst;
	unsigned char	*sr;
	size_t			a;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	a = 0;
	if (!sr && !dst)
		return (NULL);
	if (dst > sr)
	{
		while (len-- > 0)
			dst[len] = sr[len];
	}
	else
	{
		while (a < len)
		{
			dst[a] = sr[a];
			a++;
		}
	}
	return (dest);
}
