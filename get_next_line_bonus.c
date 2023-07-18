/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:20:48 by manuelgomez       #+#    #+#             */
/*   Updated: 2023/07/18 15:58:52 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		line;
	size_t		index;

	index = 0;
	if (BUFFER_SIZE < 0 || read(fd, 0, 0) < 1)
	{
		while (buffer[fd][index])
			buffer[fd][index++] = 0;
		return (0);
	}
	line = NULL;
	while (buffer[fd][0] || read(fd, buffer[fd], BUFFER_SIZE))
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_manage_buffer(buffer[fd]))
			break ;
	}
	return (line);
}
