/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 04:16:34 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 04:00:52 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*big;
	unsigned char	*little;
	size_t			i;

	if (s1 == s2 || n == 0)
		return (0);
	little = (unsigned char *) s2;
	big = (unsigned char *) s1;
	i = 0;
	while (i < n)
	{
		if (big[i] != little[i])
			return (big[i] - little[i]);
		i++;
	}
	return (0);
}
