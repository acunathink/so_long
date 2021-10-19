/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 09:33:43 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 04:52:25 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		n;

	if (*needle == '\0')
		return (haystack);
	i = 0;
	n = ft_strlen(needle);
	while (haystack[i] && n <= len--)
	{
		if (ft_memcmp(&haystack[i], needle, n) == 0)
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}
