/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:21:23 by pmalope           #+#    #+#             */
/*   Updated: 2019/07/03 14:48:42 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_func(int index, char **tab)
{
	int	i;

	i = 0;
	while (tab[index][i] != '\n' && tab[index][i] != '\0')
		i++;
	return (i);
}

static int	ft_new_line(int fd, char **line, char **tab, int line_size)
{
	int		len;
	char	*ptr;

	len = ft_func(fd, tab);
	if (tab[fd][len] == '\n')
	{
		*line = ft_strsub(tab[fd], 0, len);
		ptr = ft_strdup(tab[fd] + len + 1);
		ft_strdel(tab[fd]);
		tab[fd] = ptr;
		if (tab[fd][0] == '\0')
			ft_strdel(&tab[fd]);
	}
	else if (tab[fd][len] == '\0')
	{
		if (line_size == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(tab[fd]);
		ft_strdel(&tab[fd]);
	}
	return (1);
}

static int	ft_read_line(int fd, char *buf, char **tab)
{
	int		len;
	char	*join_buf;

	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		if (tab[fd] == NULL)
			tab[fd] = ft_strnew(1);
		join_buf = ft_strjoin(tab[fd], buf);
		free(tab[fd]);
		tab[fd] = join_buf;
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

	if (fd < 0 || !line)
		return (-1);
	if ((n = ft_read_line(fd, buffer, tmp_buf)) < 0)
		return (-1);
	else if (n == 0 && (tmp_buf[fd] == NULL || tmp_buf[fd][0] == '\0'))
		return (0);
	res = ft_new_line(fd, line, tmp_buf, n);
	return (res);
}
