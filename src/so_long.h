/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:47:01 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/29 18:35:00 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_images
{
	void	*colect;
	void	*wall;
	void	*grass;
	void	*player;
	void	*exit;
	int		wid;
	int		hei;
}			t_images;

# define COLL "./images/collectable.xpm"
# define WALL "./images/wall.xpm"
# define GRAS "./images/grass.xpm"
# define EXIT "./images/exit.xpm"
# define PLAY "./images/player.xpm"

typedef struct s_mapconf
{
	char		**map;
	size_t		col;
	size_t		row;
	size_t		wid;
	size_t		hei;
	size_t		colect;
	size_t		player;
	size_t		exit;
	size_t		step;
	size_t		x;
	size_t		y;
	void		*mlx;
	void		*window;
	t_images	*img;
}			t_mapconf;

void	so_parsing_map(char ***av, t_mapconf *game);
void	so_arg_check(int ac, char ***av);
void	so_parsing_map(char ***av, t_mapconf *game);
int		so_end_with_error(char *msg);
void	so_long(t_mapconf *game);
void	so_put_image(int x, int y, t_mapconf *gm);

#endif
