/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 04:34:30 by ojospeh           #+#    #+#             */
/*   Updated: 2021/08/25 01:31:59 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_save(char **brr, char const *s, char c)
{
	int	cnt;
	int	i;
	int	j;

	cnt = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while ((s[i] != c) && s[i])
		{
			brr[cnt][j] = s[i];
			j++;
			i++;
		}
		while (s[i] == c)
			i++;
		if (brr[cnt] == NULL)
			break ;
		brr[cnt][j] = '\0';
		if (brr[cnt][0] != '\0')
			cnt++;
	}
	return (brr);
}

static char	**ft_fallfree(char **fill, int ct)
{
	while (--ct > 0)
		free(fill[--ct]);
	free(fill);
	return (fill);
}

static char	**ft_fill(char **fill, int len, char const *str, char dil)
{
	int			ct;
	int			c;
	int			i;
	char const	*tmp;

	ct = 0;
	i = 0;
	tmp = str;
	while (ct < len)
	{
		c = 0;
		while (*str && *str++ != dil)
			c++;
		while (*str == dil)
			str++;
		if (c != 0)
		{
			fill[ct] = (char *)malloc(sizeof(char) * (c + 1));
			if (fill[ct++] == NULL)
				return (ft_fallfree(fill, ct));
		}
	}
	fill[ct] = NULL;
	return (ft_save(fill, tmp, dil));
}

static int	ft_cntcheck(char const *s, char c)
{
	int			i;
	int			cnt;
	char const	*tmp;

	tmp = s;
	cnt = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c && *s)
				s++;
			++cnt;
		}
		if (*s)
			s++;
	}
	if (*tmp == c && cnt > 0)
		cnt--;
	if (*(s - 1) == c)
		cnt--;
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		cnt;

	if (!s || !ft_strncmp(s, "", 1))
	{
		arr = (char **)malloc (sizeof(char *));
		if (arr == NULL)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	if (c == 0)
	{
		arr = (char **)malloc (sizeof (char *) * 2);
		if (arr == NULL)
			return (NULL);
		arr[0] = ft_strdup(s);
		arr[1] = NULL;
		return (arr);
	}
	cnt = ft_cntcheck(s, c);
	arr = (char **)malloc ((sizeof (char *) * (++cnt + 1)));
	if (arr == NULL)
		return (NULL);
	return (ft_fill(arr, cnt, s, c));
}
