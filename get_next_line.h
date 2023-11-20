/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:42:04 by almarico          #+#    #+#             */
/*   Updated: 2023/11/11 15:49:03 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif // !BUFFER_SIZE

void	ft_cut_buffer(char *buffer);
char	*ft_mod_join(char *line, char *buffer);
char	*get_next_line(int fd);
int		ft_mod_strchr(char *buffer);
int		ft_mstrlen(char *str);
char	*ft_test_end(char *dest);
char	*ft_free(char *line);

#endif
