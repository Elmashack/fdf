/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nluya <nluya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:38:24 by elmas             #+#    #+#             */
/*   Updated: 2021/05/09 15:44:37 by nluya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	int	i;

	i = 0;
	if (n < 0 || n == 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_dec(int n)
{
	int	dec;

	dec = 1;
	n /= 10;
	while (n)
	{
		dec *= 10;
		n /= 10;
	}
	return (dec);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		i;
	long	dec;
	long	dup;

	dup = (long)n;
	dec = ft_dec(n);
	i = ft_size(n);
	num = (char *)malloc(sizeof(char) * (i + 1));
	if (num == NULL)
		return (NULL);
	i = 0;
	if (dup < 0)
	{
		dup = -dup;
		num[i++] = '-';
	}
	while (dec > 0)
	{
		num[i++] = dup / dec + 48;
		dup = dup % dec;
		dec /= 10;
	}
	num[i] = '\0';
	return (num);
}
