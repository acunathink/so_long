/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojospeh <ojospeh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:04:41 by ojospeh           #+#    #+#             */
/*   Updated: 2021/10/26 16:42:20 by ojospeh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_saveline(char **gnl, char **buff, char **line, int readres)
{
	char	*n;

	if (ft_find_nl(buff, line, &n, 0))
	{
		*line = ft_getn(line, n, gnl, buff);
		return (0);
	}
	if (*gnl && *buff)
		*gnl = so_stjoin(gnl, buff);
	else if (*buff && readres)
		*gnl = so_strdup(*buff, 0);
	if (*buff != NULL)
		ft_allfree(buff, gnl, 0);
	if (*gnl == NULL)
		readres = -1;
	if (*gnl != NULL && *line == NULL && readres == 0)
	{
		*line = so_strdup(*gnl, 0);
		ft_allfree(gnl, buff, 0);
	}
	return (readres);
}

char	*ft_getn(char **line, char *n, char **gnl, char **buff)
{
	*n++ = '\0';
	*line = so_strdup(*buff, 1);
	if (*gnl)
	{
		*gnl = so_stjoin(gnl, &n);
		if (*gnl == NULL)
		{
			ft_allfree(line, buff, -1);
			return (NULL);
		}
	}
	else if (*n)
	{
		*gnl = so_strdup(n, 0);
		if (*gnl == NULL)
			ft_allfree(line, buff, 0);
	}
	ft_allfree(buff, line, 0);
	return (*line);
}

int	ft_allfree(char **fred, char **all, int resread)
{
	if (resread < 0)
	{
		if (*all != NULL)
			free (*all);
		*all = NULL;
		if (*fred != NULL)
			free (*fred);
		*fred = NULL;
		return (-1);
	}
	if (*fred != NULL)
		free (*fred);
	*fred = NULL;
	return (0);
}

int	ft_getbuff(int fd, char **gnl, char **buff)
{
	int		resread;

	*buff = (char *)malloc(BUFFER_SIZE + 1);
	if (*buff == NULL)
		return (ft_allfree(gnl, buff, -1));
	resread = read(fd, *buff, BUFFER_SIZE);
	if (resread < 0 || (!resread && *gnl == NULL))
		return (ft_allfree(gnl, buff, -1));
	else
	{
		(*buff)[resread] = '\0';
		if (*gnl && resread > 0)
			*buff = so_stjoin(gnl, buff);
		else if (*gnl == NULL && resread == 0)
			ft_allfree(buff, gnl, 0);
	}
	return (resread);
}

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*n;
	char		*buff;
	char		*line;
	int			readres;

	if (BUFFER_SIZE < 1 || fd < 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	line = NULL;
	readres = 1;
	while (readres > 0)
	{
		if (ft_find_nl(&gnl, &line, &n, 1))
			return (line);
		else
		{
			readres = ft_getbuff(fd, &gnl, &buff);
			if (readres < 0)
				return (NULL);
			readres = ft_saveline(&gnl, &buff, &line, readres);
		}
	}
	return (line);
}
