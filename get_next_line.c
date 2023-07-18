/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelgomezgomez <manuelgomezgomez@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:27:07 by manuelgomez       #+#    #+#             */
/*   Updated: 2023/07/13 10:48:03 by manuelgomez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		index;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buffer[index])
			buffer[index++] = 0;
		return (0);
	}
	line = NULL;
	while (buffer[0] != 0 || read(fd, buffer, BUFFER_SIZE))
	{	
		line = ft_strjoin(line, buffer);
		if (ft_menage_buffer(buffer))
			break ;
	}
	return (line);
}
