/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:17:39 by nluya             #+#    #+#             */
/*   Updated: 2021/05/09 16:20:41 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static void	*ft_free(char **arr_s)
{
	int	i;

	i = 0;
	while (arr_s[i])
		free(arr_s[i++]);
	free(arr_s);
	return (NULL);
}

static int	ft_strnum(char const *s, char c)
{
	size_t	num;
	char	check;

	check = 1;
	num = 0;
	while (*s)
	{
		if (*(s++) != c)
		{
			if (check)
				num++;
			check = 0;
		}
		else
			check = 1;
	}
	return (num);
}

static int	ft_strsize(char const *str, char delim)
{
	int	len;

	len = 0;
	while (*str == delim)
		str++;
	while (str[len] && str[len] != delim)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**s_arr;
	int		num_s;
	int		i;
	int		len;

	i = 0;
	if (!s)
		return (NULL);
	num_s = ft_strnum(s, c);
	s_arr = (char **)malloc(sizeof(char *) * (num_s + 1));
	if (s_arr == NULL)
		return (NULL);
	while (i < num_s)
	{
		len = ft_strsize(s, c);
		while (*s == c)
			s++;
		s_arr[i] = ft_substr(s, 0, len);
		if (s_arr[i] == NULL)
			ft_free(s_arr);
		i++;
		s += len;
	}
	s_arr[i] = NULL;
	return (s_arr);
}
