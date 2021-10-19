/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:56:31 by ojospeh           #+#    #+#             */
/*   Updated: 2021/08/25 01:42:29 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	s;
	size_t	i;

	if (!dst)
		return (0);
	s = 0;
	while (src[s] != '\0')
		s++;
	if (dstsize == 0)
		return (s);
	i = 0;
	while (i < (dstsize - 1) && i < s)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s);
}
