/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:47:01 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/31 20:39:21 by ojospeh          ###   ########.fr       */
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
	void	*black;
	int		wid;
	int		hei;
}			t_images;

# define COLL "./images/collectable_h.xpm"
# define WALL "./images/wall.xpm"
# define GRAS "./images/grass_h.xpm"
# define EXIT "./images/exit.xpm"
# define PLAY "./images/player_h.xpm"
# define BLACK "./images/black.xpm"

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
	int			key;
	void		*mlx;
	void		*window;
	t_images	*img;
}				t_mapconf;

# define WINNER -777
# define PRESS_ESC 53
# define PRESS_W 13
# define PRESS_A 0
# define PRESS_S 1
# define PRESS_D 2
# define MAP 46
# define PK 40
# define P 35
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define COLOR 8

void	so_parsing_map(char ***av, t_mapconf *game);
void	so_arg_check(int ac, char ***av);
void	so_parsing_map(char ***av, t_mapconf *game);
int		so_end_with_error(char *msg);
void	so_long(t_mapconf *game);
void	so_put_image(int x, int y, t_mapconf *gm);
int		so_move_player(int key, t_mapconf *gm);
int		so_press_key(int keycode, t_mapconf *gm);
int		so_close_game(int keycode, t_mapconf *gm);
void	so_print_map(t_mapconf *mc);

#endif
