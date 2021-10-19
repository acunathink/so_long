/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:15:43 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 07:24:25 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(char const *s, unsigned int start, size_t len)
{
	if (ft_strlen(s) < start)
		return (0);
	if (len > ft_strlen(&s[start]))
		return (ft_strlen(&s[start]));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	l = ft_check(s, start, len);
	sub = (char *) malloc(sizeof(char) * (l + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < l)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
