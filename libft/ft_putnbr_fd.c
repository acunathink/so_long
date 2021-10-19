/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 17:24:09 by ojospeh           #+#    #+#             */
/*   Updated: 2021/05/13 16:05:46 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(fd, &s[i++], 1);
}

static void	ft_pow(int n, char *num)
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
}

static char	*ft_itoa(char *res, int n)
{
	char		num[13];
	int			i;
	int			j;

	i = 0;
	if (n < 0)
	{
		num[i++] = '-';
		n *= -1;
	}
	ft_pow(n, &num[i]);
	i = 0;
	j = 0;
	if (num[i++] == '-')
		res[j++] = '-';
	while (num[i] == '0')
		i++;
	while (num[i] != '\0')
		res[j++] = num[i++];
	res[j] = '\0';
	return (res);
}

void	ft_putnbr_fd(int n, int fd)
{
	char		res[13];
	char		ch;

	if (n >= 0 && n < 10)
	{
		ch = n + '0';
		write(fd, &ch, 1);
		return ;
	}
	if (n == 2147483647)
	{
		write(fd, "2147483647", 10);
		return ;
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	ft_putendl_fd(ft_itoa(res, n), fd);
}
