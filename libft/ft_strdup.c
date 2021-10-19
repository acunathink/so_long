/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:30:52 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 05:12:21 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned long int	ft_strlen(const char *s)
{
	unsigned long int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (++l);
}

char	*ft_strdup(const char *str)
{
	unsigned long int	len;
	unsigned long int	i;
	char				*dup;

	len = ft_strlen(str);
	dup = (char *) malloc(sizeof(char) * len);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	return (dup);
}
