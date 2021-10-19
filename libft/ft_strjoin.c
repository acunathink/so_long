/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 00:22:16 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 07:20:34 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long int		s1_l;
	unsigned long int		s2_l;
	unsigned long int		i;
	char					*join;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	join = (char *) malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (join == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	s1_l = 0;
	while (s1_l < s2_l)
		join[i++] = s2[s1_l++];
	join[i] = '\0';
	return (join);
}
