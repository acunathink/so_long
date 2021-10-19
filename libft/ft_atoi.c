/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:17:40 by ojospeh           #+#    #+#             */
/*   Updated: 2021/08/26 22:19:08 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sum;
	int	sgn;
	int	num;
	int	n;

	sum = 0;
	sgn = 1;
	i = 0;
	while ((str[i] >= 011 && str[i] <= 015) || str[i] == 040)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sgn = -1;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n++;
		num = str[i++] - 48;
		sum *= 10;
		sum = num + sum;
		if (n > 10)
			return ((1 + sgn) * -1 / 2);
	}
	return (sum * sgn);
}
