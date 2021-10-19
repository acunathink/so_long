/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:39:08 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/08 14:37:25 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	if (s == NULL)
		return (NULL);
	dup = ft_strdup(s);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (dup[i] != '\0')
	{
		dup[i] = f(i, s[i]);
		i++;
	}
	return (dup);
}
