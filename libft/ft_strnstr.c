/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:15:37 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 16:24:54 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_ocurecheck(const char *dst, const char *src, size_t len)
{
	while (*src)
	{
		if (*dst != *src || len < 1)
			return (NULL);
		src++;
		dst++;
		len--;
	}
	return ((char *)dst);
}

char	*ft_strnstr(const char *dst, const char *src, size_t l)
{
	if (*src == 0)
		return ((char *)dst);
	while (l > 0 && *dst)
	{
		if (ft_ocurecheck(dst, src, l) != NULL)
			return ((char *)dst);
		dst++;
		l--;
	}
	return (NULL);
}
