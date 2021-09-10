/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:36:44 by elmas             #+#    #+#             */
/*   Updated: 2021/05/09 16:23:23 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newch;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	newch = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (newch == NULL)
		return (NULL);
	while (s[i])
	{
		newch[i] = f(i, s[i]);
		i++;
	}
	newch[i] = '\0';
	return (newch);
}
