/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:26:57 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/03 16:42:57 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_IMAGES_H
# define SO_LONG_IMAGES_H

typedef struct s_images
{
	void	*colect;
	void	*wall;
	void	*grass;
	void	*player[4];
	void	*ghost[3][4];
	void	*exit[4];
	void	*black;
	void	*undt;
	int		wid;
	int		hei;
}			t_images;

# define WALL "./images/wall.xpm"
# define COLL "./images/collectable_h.xpm"
# define GRAS "./images/grass_h.xpm"
# define BLACK "./images/black.xpm"
# define UND_T "./images/under_text_3.xpm"
# define EXIT "./images/exit00.xpm"
# define EXIT_NUM_AT 14
# define PLAY "./images/Freddy00.xpm"
# define PLAY_NUM_AT 16
# define GHOST "./images/ghost00.xpm"
# define GHOST_NUM 15

#endif