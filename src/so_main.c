/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:21:55 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/25 20:55:46 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_map_conf_init(t_mapconf *mc)
{
	mc = (t_mapconf *)malloc(sizeof(t_mapconf));
	if (!mc)
	{
		perror(RED "Error" WHT);
		exit(1);
	}
	*mc = (t_mapconf)
	{
		.col = 0, .row = 0, .x = 0, .y = 0, .w_height = 0, .w_width = 0,
		.player = 0, .exit = 0, .colect = 0, .step = 0, .map = NULL
	};
	mc->map = (char **)malloc(sizeof(char **));
	if (!mc->map)
	{
		perror(RED "Error" WHT);
		exit(1);
	}
}

void	so_parsing_map(char ***av, t_mapconf **game)
{
	int			fd;
	t_mapconf	mc;
	char		*tmp;

	fd = open((*av)[1], O_RDONLY);
	if (fd < 0)
	{
		perror(RED "Error" WHT);
		exit(1);
	}
	so_map_conf_init(&mc);
	tmp = get_next_line(fd);
	mc.col = ft_strlen(tmp);
	while (tmp)
	{
		mc.row++;
		ft_putstr_fd(tmp, 1);
		ft_putstr_fd(YELL " - ", 1);
		ft_putnbr_fd(ft_strlen(tmp), 1);
		ft_putendl_fd(WHT, 1);
		if (mc.col != ft_strlen(tmp))
		{
			ft_putendl_fd(RED "Error:" WHT " a row of unequal length", 2);
			exit (1);
		}
		tmp = get_next_line(fd);
	}
	*game = &mc;
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
		if (ft_strncmp(&((*av)[1][i - 4]), ".ber", 4))
		{
			ft_putendl_fd(RED "Error:" WHT " need map file in .ber format", 2);
			return (0);
		}
	}
	else
	{
		ft_putendl_fd(RED "Error:" WHT " need map file in .ber format", 2);
		return (0);
	}
	return (1);
}

void	so_print_map(t_mapconf *mc)
{
	size_t	i;

	i = 0;
	while (i < mc->row)
		ft_putendl_fd(mc->map[i++], 1);
}

int	main(int argc, char **argv)
{
	t_mapconf	*game;

	if (!so_argcheck(argc, &argv))
		exit(1);
	so_parsing_map(&argv, &game);
	if (!game)
		exit(1);
	so_print_map(game);
	return (0);
}
