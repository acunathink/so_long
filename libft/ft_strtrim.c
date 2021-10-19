/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 02:23:27 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/12 17:43:32 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *str, char const *set)
{
	int	s;
	int	i;
	int	del;

	s = 0;
	del = 1;
	while (del != 0)
	{
		del = 0;
		i = 0;
		while (set[i] != '\0' && str[s])
		{
			if (set[i++] == str[s])
				del = 1;
		}
		s++;
	}
	return (s - 1);
}

static int	ft_end(char const *str, char const *set)
{
	int	e;
	int	i;
	int	del;

	e = ft_strlen(str);
	del = 1;
	e--;
	while (del != 0 && e > 0)
	{
		del = 0;
		i = 0;
		while (set[i] != '\0')
		{
			if (set[i++] == str[e])
				del = 1;
		}
		e--;
	}
	return (e + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		s;
	int		e;
	int		len;

	if (!s1)
	{
		trim = malloc(sizeof (char));
		*trim = '\0';
		return (trim);
	}
	s = ft_start(s1, set);
	e = ft_end(s1, set);
	len = e - s + 1;
	if (len < 0)
		len = 0;
	trim = (char *) malloc(sizeof(char) * (len + 1));
	if (trim == NULL)
		return (NULL);
	len = 0;
	while (s <= e)
		trim[len++] = s1[s++];
	trim[len] = '\0';
	return (trim);
}
