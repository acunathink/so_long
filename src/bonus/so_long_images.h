/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_images.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:26:57 by ojospeh           #+#    #+#             */
/*   Updated: 2021/11/02 21:29:30 by ojospeh          ###   ########.fr       */
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
	void	*exit[4];
	void	*black;
	void	*undt;
	int		wid;
	int		hei;
}			t_images;

# define COLL "./images/collectable_h.xpm"
# define WALL "./images/wall.xpm"
# define GRAS "./images/grass_h.xpm"
# define EXIT "./images/exit0.xpm"
# define PLAY "./images/Freddy0.xpm"
# define BLACK "./images/black.xpm"
# define UND_T "./images/under_text_3.xpm"

#endif