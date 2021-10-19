/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 23:36:41 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/07 15:37:31 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ld;
	size_t	ls;
	size_t	i;
	size_t	l;

	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	if (dstsize <= ld)
		return (ls + dstsize);
	l = ld;
	i = 0;
	while ((l < dstsize - 1) && src[i])
		dst[l++] = src[i++];
	dst[l] = '\0';
	return (ls + ld);
}
