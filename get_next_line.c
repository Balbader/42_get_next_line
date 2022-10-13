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
	int		i;
	char	*temp;

	i = 1;
	while (i != '\0')
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (0);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

// Take the line that read the fd
// and extract and save the new characters to stash
char	*ft_extract_from_line(char *line)
{
	char	*stash;
	size_t	start;

	start = 0;
	while (line[start] != '\n' && line[start] != '\0')
		start++;
	if (line[start] == '\0' || line[1] == '\0')
		return (NULL);
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
