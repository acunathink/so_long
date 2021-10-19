/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:16:27 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/05 16:51:05 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*set;
	size_t			i;

	set = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		set[i] = (unsigned char)c;
		i++;
	}
	return ((void *) set);
}
