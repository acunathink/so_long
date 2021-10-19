/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 06:20:19 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/13 13:05:31 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_pow(int n, char *num)
{
	int	pow[11];
	int	i;
	int	cnt;

	pow[10] = 1;
	i = 9;
	while (i > 0)
	{
		pow[i] = pow[i + 1] * 10;
		i--;
	}
	while (i < 10)
	{
		cnt = 0;
		i++;
		while (n >= pow[i])
		{
			n -= pow[i];
			cnt++;
		}
		*num++ = cnt + '0';
	}
	*num = '\0';
	return (num);
}

static char	*ft_max(int n, char *res)
{
	if (n == 0 || n == -0)
	{
		res = ft_strdup("0");
		return (res);
	}
	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		return (res);
	}
	else
	{
		res = ft_strdup("2147483647");
		return (res);
	}
}

static char	*ft_fill(char *num, char *res)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (num[i] == '-')
	{
		res[j++] = '-';
		i++;
	}
	while (num[i] == '0')
		i++;
	while (num[i] != '\0')
		res[j++] = num[i++];
	res[j] = '\0';
	return (res);
}

static int	ft_zskip(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i] == '0')
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char	num[12];
	char	*res;
	int		i;
	int		m;

	res = NULL;
	if (n == -2147483648 || n == 2147483647 || n == 0 || n == -0)
		return (ft_max(n, res));
	m = 0;
	if (n < 0)
	{
		num[m++] = '-';
		n *= -1;
	}
	res = ft_pow(n, &num[m]);
	i = ft_zskip(&num[0]);
	res = (char *)malloc(sizeof(char) * (ft_strlen(&num[i]) + m + 1));
	if (res == NULL)
		return (NULL);
	res = ft_fill(num, res);
	return (res);
}
