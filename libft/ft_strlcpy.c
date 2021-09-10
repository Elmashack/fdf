/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:22:19 by nluya             #+#    #+#             */
/*   Updated: 2021/09/05 11:40:14 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcpy(char *dst, const char *src, size_t i)
{
	int	len;

	len = 0;
	if (!src || !dst)
		return (0);
	while (src[len])
		len++;
	if (i == 0)
		return (len);
	if (i != 0)
	{
		while (i > 1 && *src != '\0')
		{
			*dst++ = *src++;
			i--;
		}
	}
	*dst = '\0';
	return (len);
}
