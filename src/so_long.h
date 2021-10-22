/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:47:01 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/22 03:30:35 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

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

#endif
