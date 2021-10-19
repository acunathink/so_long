/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 03:41:17 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/02 03:59:02 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*srch;
	unsigned char	ch;

	srch = (unsigned char *) s;
	ch = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (*srch++ == ch)
			return (--srch);
		i++;
	}
	return (NULL);
}
