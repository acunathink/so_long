/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:58:02 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/25 20:10:25 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char				*get_next_line(int fd);
char				*ft_getn(char **line, char *n, char **gnl, char **buff);
char				*ft_gnl(char *nl, char *n, char **line);
//int					ft_getline(int fd, char **nl, char **line);
int					ft_saveline(char **g, char **b, char **l, int readres);
int					ft_find_nl(char **gnl, char **line, char **n, int flag);
char				*so_stjoin(char **s1, char **s2);
char				*so_strdup(const char *str, int flag);
unsigned long int	so_strlen(const char *s);
int					ft_allfree(char **gnl, char **line, int resread);
int					ft_getbuff(int fd, char **gnl, char **buff);

#endif
