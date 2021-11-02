/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_mapcheck_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:50:36 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/02 20:13:01 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	so_arg_check(int ac, char ***av)
{
	int	i;

	if (ac == 1 || !(*av)[1] || (*av)[1][0] == '\0')
		exit(so_end_with_error("empty file path"));
	i = 0;
	while ((*av)[1][i] != '\0')
		++i;
	if (i > 4)
	{
		if (ft_strncmp(&((*av)[1][i - 4]), ".ber", 4))
			exit(so_end_with_error("need map file in .ber format"));
	}
	else
		exit(so_end_with_error("need map file in .ber format"));
}

void	add_line(char **gnl, t_list *pline)
{
	t_list	*nline;

	nline = (t_list *)malloc(sizeof(t_list));
	pline->next = nline;
	nline->content = *gnl;
	nline->next = NULL;
}

int	so_add_list_of_lines(int fd, t_list **lines)
{
	int		count;
	char	*tmp;
	t_list	*prev;

	count = 0;
	tmp = get_next_line(fd);
	if (tmp)
	{
		*lines = (t_list *)malloc(sizeof(t_list));
		(**lines).content = tmp;
		(**lines).next = NULL;
		++count;
	}
	prev = *lines;
	while (tmp)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			return (count);
		add_line(&tmp, prev);
		prev = prev->next;
		++count;
	}
	return (-1);
}

void	so_map_conf_init(t_mapconf *game, int count)
{
	*game = (t_mapconf)
	{
		.col = 0, .row = 0, .x = 0, .y = 0, .hei = 0, .wid = 0, .key = 0,
		.player = 0, .exit = 0, .colect = 0, .step = 0, .map = NULL
	};
	game->map = (char **)malloc(sizeof(char *) * count);
	if (!game->map)
	{
		perror(RED "Error" WHT);
		exit(1);
	}
}

void	so_parsing_map(char ***av, t_mapconf *game)
{
	int		fd;
	int		count;
	t_list	*tmp;
	t_list	*lines;
	t_list	*leak;

	fd = open((*av)[1], O_RDONLY);
	if (fd < 0)
		exit(so_end_with_error("perror"));
	count = so_add_list_of_lines(fd, &lines);
	if (count <= 0)
		exit(so_end_with_error("have not map here"));
	so_map_conf_init(game, count);
	tmp = lines;
	game->col = ft_strlen(tmp->content);
	while (tmp)
	{
		game->map[game->row] = tmp->content;
		if (game->col != ft_strlen(game->map[game->row]))
			exit(so_end_with_error("wrong map format"));
		game->row++;
		leak = tmp;
		tmp = tmp->next;
		free(leak);
	}
}
