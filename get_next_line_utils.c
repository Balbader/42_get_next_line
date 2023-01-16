/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 07:07:32 by baalbade          #+#    #+#             */
/*   Updated: 2022/11/29 08:27:39 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	k = 0;
	i = 0;
	while (s1[i])
		res[k++] = s1[i++];
	j = 0;
	while (s2[j])
		res[k++] = s2[j++];
	res[k] = '\0';
	return (res);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;
	int		j;

	dup = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!dup)
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
		dup[j++] = str[i++];
	dup[j] = '\0';
	return (dup);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		sub[j++] = s[start++];
		i++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

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
