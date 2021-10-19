/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 02:00:29 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 00:42:33 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static unsigned char	*ft_cf(unsigned char *d, unsigned char *copy, size_t l)
{
	size_t			i;

	if (d < copy)
	{
		i = 0;
		while (i < l)
		{
			d[i] = copy[i];
			i++;
		}
		return (d);
	}
	else
	{
		i = l;
		while (i-- > 0)
			d[i] = copy[i];
		return (d);
	}
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (len > 0)
		d = ft_cf(d, s, len);
	return ((void *) d);
}
