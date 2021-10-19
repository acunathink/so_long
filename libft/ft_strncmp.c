/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:54:12 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/11 07:23:40 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ft;
	unsigned char	*sd;
	size_t			i;

	if (n == 0)
		return (0);
	ft = (unsigned char *) s1;
	sd = (unsigned char *) s2;
	i = 0;
	while (ft[i] == sd[i] && i < (n - 1) && sd[i])
		i++;
	return ((unsigned char)ft[i] - (unsigned char)sd[i]);
}
