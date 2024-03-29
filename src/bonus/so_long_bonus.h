/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:47:01 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/03 17:35:03 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# include "so_long_images.h"

typedef struct s_ghost
{
	int		n0;
	int		n1;
	size_t	x;
	size_t	y;
	char	ex[2];
	void	*next;

}			t_ghost;

typedef struct s_mapconf
{
	char		**map;
	size_t		col;
	size_t		row;
	size_t		wid;
	size_t		hei;
	size_t		colect;
	size_t		player;
	t_ghost		*ghost;
	size_t		exit;
	size_t		step;
	size_t		x;
	size_t		y;
	size_t		loop;
	int			key;
	void		*mlx;
	void		*window;
	t_images	*img;
}				t_mapconf;

# define WINNER -777	//custom keycode
# define PRESS_ESC 53	//press ESC to quit the game
# define PRESS_W 13
# define PRESS_A 0
# define PRESS_S 1
# define PRESS_D 2
# define MAP 46			//press M to print map in STDOUT
# define PK 40			//press K to print keycode in STDOUT
# define P 35			//press P to YELLOW output
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define COLOR 8		//press C to default color in output

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
int		so_atloop(t_mapconf *gm);
void	so_print_image(t_mapconf *game);
void	so_print_sprite(t_mapconf *game, char sprite);
void	so_add_ghost(t_mapconf *gm, size_t y, size_t x);

#endif
