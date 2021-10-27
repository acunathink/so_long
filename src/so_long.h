/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:47:01 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/27 17:29:43 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_mapconf
{
	char	**map;
	size_t	col;
	size_t	row;
	size_t	w_width;
	size_t	w_height;
	size_t	colect;
	size_t	player;
	size_t	exit;
	size_t	step;
	size_t	x;
	size_t	y;
}			t_mapconf;

void	so_parsing_map(char ***av, t_mapconf *game);
void	so_arg_check(int ac, char ***av);
void	so_parsing_map(char ***av, t_mapconf *game);
int		so_end_with_error(char *msg);

#endif
