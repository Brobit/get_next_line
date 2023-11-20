/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:41:48 by almarico          #+#    #+#             */
/*   Updated: 2023/11/11 20:13:40 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *line)
{
	free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = {};
	char		*line;
	int			res_read;

	line = NULL;
	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	if (ft_mod_strchr(buffer))
	{
		ft_cut_buffer(buffer);
		line = ft_mod_join(line, buffer);
	}
	res_read = 1;
	while (res_read > 0 && !ft_mod_strchr(buffer))
	{
		res_read = read(fd, buffer, BUFFER_SIZE);
		if (res_read == -1)
			return (ft_free(line));
		if (res_read == 0)
			return (line);
		buffer[res_read] = '\0';
		line = ft_mod_join(line, buffer);
	}
	return (line);
}
/*
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	char	*buf;

	fd = 0;
	buf = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDWR);
//		write(fd, buf, 0);
		if (fd == -1)
		{
			close(fd);
			return (1);
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
//			printf("here is a line\n");
			ft_putstr_fd(line, 0);
			line = get_next_line(fd);
		}
		free(line);
		close(fd);
	}
	return (0);
}
*/
