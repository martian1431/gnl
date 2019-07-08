/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:21:23 by pmalope           #+#    #+#             */
/*   Updated: 2019/07/06 11:32:43 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_find_newline(int pos, char **tab)
{
	int	i;

	i = 0;
	while (tab[pos][i] != '\n' && tab[pos][i] != '\0')
		i++;
	return (i);
}

static int	ft_next_line(int fd_pos, char **line, char **tab, int length)
{
	int		res;
	int		index;
	char	*ptr;

	index = ft_find_newline(fd_pos, tab);
	if (tab[fd_pos][index] == '\n')
	{
		*line = ft_strsub(tab[fd_pos], 0, index);
		ptr = ft_strdup(tab[fd_pos] + index + 1);
		ft_strdel(&tab[fd_pos]);
		tab[fd_pos] = ptr;
		if (tab[fd_pos][0] == '\0')
			ft_strdel(&tab[fd_pos]);
	}
	else if (tab[fd_pos][index] == '\0')
	{
		if (length == BUFF_SIZE)
		{
			res = get_next_line(fd_pos, line);
			return (res);
		}
		*line = ft_strdup(tab[fd_pos]);
		ft_strdel(&tab[fd_pos]);
	}
	return (1);
}

static int	ft_read_line(int fd, char *buf, char **tab)
{
	int		pos;
	int		len;
	char	*ptr;

	pos = fd;
	if (tab[pos] == NULL)
		tab[pos] = ft_strnew(1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		ptr = ft_strjoin(tab[pos], buf);
		free(tab[pos]);
		tab[pos] = ptr;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (len);
}

int			get_next_line(const int fd, char **line)
{
	int			n;
	int			res;
	static char	*tmp_buf[1024];
	char		buffer[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if ((n = ft_read_line(fd, buffer, tmp_buf)) < 0)
		return (-1);
	if (n == 0 && (tmp_buf[fd] == NULL || tmp_buf[fd][0] == '\0'))
		return (0);
	res = ft_next_line(fd, line, tmp_buf, n);
	return (res);
}
