/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elmas <elmas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:17:39 by elmas             #+#    #+#             */
/*   Updated: 2021/05/15 09:53:10 by elmas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isset(char s, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	int		size;

	begin = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[begin] && ft_isset(s1[begin], set))
		begin++;
	while (end > begin && ft_isset(s1[end - 1], set))
		end--;
	size = end - begin;
	return (ft_substr(s1, begin, size));
}
