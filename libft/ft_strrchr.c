/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 08:12:36 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/12 16:32:53 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (c == '\0')
		return (&str[i]);
	while (i > -1)
	{
		if (str[i] == (unsigned char) c)
			return (&str[i]);
		--i;
	}
	return (0);
}
