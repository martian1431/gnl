/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmalope <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:57:01 by pmalope           #+#    #+#             */
/*   Updated: 2019/07/03 14:44:52 by pmalope          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		fd1;
	int		res;
	char	*line;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	fd1 = open(argv[2], O_RDONLY);
	while ((res = get_next_line(fd, &line)))
	{
		ft_putnbr(res);
		ft_putchar(' ');
		ft_putendl(line);
		free(line);
	}
	return (0);
}
