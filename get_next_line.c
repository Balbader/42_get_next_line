/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:53:53 by baalbade          #+#    #+#             */
/*   Updated: 2022/10/08 18:54:22 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *buffer, char *stash)
{
	// i = tot count of element read
	int		i;
	// *temp arr to hold stash content
	char	*temp;

	i = 1;
	while (i != '\0')
	{
		// read file
		i = read(fd, buffer, BUFFER_SIZE);

		// and make sure there is something in it
		if (i == -1)
			return (0);
		else if (i == 0)
			break ;

		// after read() initialize last element of buffer to '\0' 
		buffer[i] = '\0';

		// if stash has no content initialize it to empty str
		if (!stash)
			stash = ft_strdup("");

		// otherwise assign stash to temp
		temp = stash;
		// and reassign stash with join of temp + buffer read for every loop iteration
		stash = ft_strjoin(temp, buffer);
		// then free temp for following iteration
		free(temp);
		temp = NULL;
		
		// if '\n' is read, break
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

char	*ft_get_line(char *line)
{
	char	*stash;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = ft_read_file(fd, buffer, stash);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash = ft_get_line(line);
	return (line);
}
