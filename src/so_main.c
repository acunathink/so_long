/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/20 20:43:47 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	so_strncmp(const char *s1, const char *s2, size_t n)
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

int	so_argcheck(int ac, char ***av)
{
	int	i;
	
	if (ac == 1 || !(*av)[1] || (*av)[1][0] == '\0')
	{
		ft_putendl_fd(RED "Error:" WHT " empty file path", 2);
		return (0);
	}
	i = 0;
	while ((*av)[1][i] != '\0')
		++i;
	if (i > 4)
	{
		if (so_strncmp(&((*av)[1][i - 4]), ".ber", 4))
			ft_putendl_fd(RED "Error:" WHT " need map file in .ber format", 2);
	}
	else
		ft_putendl_fd(RED "Error:" WHT " need map file in .ber format", 2);
	return (1);
}

int	main(int argc, char **argv)
{
	if (!so_argcheck(argc, &argv))
		(void) argc;
	(void) argv;
	return (0);
}
