/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 22:58:42 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/01 15:56:10 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	so_strlen(const char *s)
{
	unsigned long int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (++l);
}

char	*so_strdup(const char *str, int flag)
{
	unsigned long int	len;
	unsigned long int	i;
	char				*dup;

	if (!str)
		return (NULL);
	len = so_strlen(str);
	dup = (char *) malloc(sizeof(char) * (len + flag));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	if (flag == 1)
	{
		dup[i - 1] = '\n';
		dup[i] = '\0';
	}
	return (dup);
}

int	ft_find_nl(char **gnl, char **line, char **n, int flag)
{
	char	*nl;

	nl = *gnl;
	if (nl)
	{
		while (*nl && *nl != '\n')
			nl++;
		if (*nl == '\n')
		{
			*n = nl;
			if (flag)
			{
				*line = ft_gnl(*gnl, *n, line);
				if (**gnl == '\0')
					ft_allfree(gnl, line, 0);
			}
			return (1);
		}
	}
	*n = NULL;
	return (0);
}

char	*ft_gnl(char *nl, char *n, char **line)
{
	*n++ = '\0';
	*line = so_strdup(nl, 1);
	if (*line == NULL && *n == '\0')
	{
		ft_allfree(&nl, line, -1);
		return (NULL);
	}
	else
	{
		while (*n)
		{
			*nl = *n++;
			nl++;
		}
		*nl = *(n);
	}
	return (*line);
}

char	*so_stjoin(char **s1, char **s2)
{
	unsigned long int		s1_l;
	unsigned long int		s2_l;
	unsigned long int		i;
	char					*join;

	s1_l = so_strlen(*s1);
	s2_l = so_strlen(*s2);
	join = (char *) malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (join == NULL)
	{
		ft_allfree(s1, s2, -1);
		return (NULL);
	}
	i = -1;
	while ((*s1)[++i] != '\0')
		join[i] = (*s1)[i];
	s1_l = 0;
	while (s1_l < s2_l)
		join[i++] = (*s2)[s1_l++];
	join[i] = '\0';
	ft_allfree(s1, s2, -1);
	return (join);
}
