/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:54:42 by baalbade          #+#    #+#             */
/*   Updated: 2022/10/08 22:32:48 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	j = 0;
	i = 0;
	while (i < len)
	{
		sub[j++] = s[start++];
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (i == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;
	int		j;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dup)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
		dup[j++] = s1[i++];
	dup[j] = '\0';
	return (dup);
}
