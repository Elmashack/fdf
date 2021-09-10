/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:13:40 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 16:22:10 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcat(char *dst, const char *src, size_t i)
{
	size_t		a;
	size_t		b;
	size_t		x;

	a = 0;
	b = 0;
	x = ft_strlen(src);
	while (*dst && b < i)
	{
		dst++;
		b++;
	}
	while ((1 + b + a < i) && *src)
	{
		*dst++ = *src++;
		a++;
	}
	if (a + b < i)
		*dst = '\0';
	return (x + b);
}
