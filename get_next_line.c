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

// Read fd and stash characters read up to '\n' and save it to line
char	*ft_read_file(int fd, char *buffer, char *stash)
{
	// i = tot count of element read
	int		i;
	// *temp arr to hold stash content
	char	*temp;

	// initialize i to 1 in order to start the loop
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

// Take the line that read the fd
// and extract and save the new characters to stash
char	*ft_extract_from_line(char *line)
{
	// array that will hold the extraction from line
	char	*stash;
	// start = starting point for the extraction
	size_t	start;

	start = 0;
	// iterate through line
	while (line[start] != '\n' && line[start] != '\0')
		start++;

	// check if end of file is reached
	if (line[start] == '\0' || line[1] == '\0')
		return (NULL);

	// make sure that stash only 
	stash = ft_substr(line, start + 1, ft_strlen(line) - start);
	if (*stash == '\0')
	{
		free(stash);
		stash = NULL;
	}
	line[start + 1] = '\0';
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
	stash = ft_extract_from_line(line);
	return (line);
}
