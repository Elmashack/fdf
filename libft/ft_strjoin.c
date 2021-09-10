/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 12:37:40 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 16:21:54 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conc;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	conc = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (conc == NULL)
		return (NULL);
	while (*s1)
		conc[i++] = *s1++;
	while (*s2)
		conc[i++] = *s2++;
	conc[i] = '\0';
	return (conc);
}
