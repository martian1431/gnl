/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:01:00 by pmalope           #+#    #+#             */
/*   Updated: 2019/08/30 16:43:18 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = 0;
	line = NULL;
	if (argc != 2)
	{
		ft_putendl("Invalid argument:");
		return (0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl("File doesn't exist");
			ft_putnbr(fd);
			return (0);
		}
	}
	while (get_next_line(fd, &line))
	{
		ft_putendl(line);
		free(line);
	}
	close (fd);
	return (0);
}
