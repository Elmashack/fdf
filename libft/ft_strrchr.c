/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:35:00 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 16:27:17 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;

	a = (char *)s;
	while (*a)
	{
		a++;
		if (*a == (char)c)
			s = a;
	}
	if (*s != (char)c)
		return (NULL);
	return ((char *)s);
}
