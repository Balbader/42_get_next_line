/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:04:33 by baalbade          #+#    #+#             */
/*   Updated: 2022/10/09 18:04:35 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*cut_until_endline(int fd, char **stash)
{
	int		len;
	char	*res;
	char	*temp;

	len = 0;
	while (stash[fd][len] != '\n' && stash[fd][len] != '\0')
		len++;
	if (saved[fd][len] == '\n')
	{
		res = ft_substr(saved[fd], 0, len + 1);
	}
}
