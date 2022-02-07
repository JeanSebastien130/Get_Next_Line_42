/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorel <jmorel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:04:04 by jmorel            #+#    #+#             */
/*   Updated: 2022/01/27 13:04:04 by jmorel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*the_end_of_the_line_gnl(char *line)
{
	char	*lastpart;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i] || !line)
		return (ft_free_gnl(line));
	lastpart = malloc(sizeof(char *) * ft_strlen_gnl(line) - i + 1);
	if (!lastpart)
		return (NULL);
	j = 0;
	i++;
	while (line[i])
	{
		lastpart[j] = line[i];
		j++;
		i++;
	}
	free(line);
	lastpart[j] = '\0';
	return (lastpart);
}

char	*the_line_gnl(char *line)
{
	int		i;
	char	*line2return;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	line2return = malloc(sizeof(char *) * i + 1);
	if (!line2return)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		line2return[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		line2return[i] = '\n';
		i++;
	}
	line2return[i] = '\0';
	return (line2return);
}

char	*other_gnl(int fd, char *buffer)
{
	int		nbytes;
	char	*buff;

	nbytes = 1;
	buff = malloc(sizeof (char *) * BUFFER_SIZE + 1);
	if (!buff)
		return (ft_free_gnl(buff));
	while (nbytes > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes < 0)
			return (ft_free_gnl(buff));
		buff[nbytes] = '\0';
		buffer = ft_strjoin_gnl(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = other_gnl(fd, buffer);
	if (!buffer)
		return (ft_free_gnl(buffer));
	line = the_line_gnl(buffer);
	buffer = the_end_of_the_line_gnl(buffer);
	return (line);
}
