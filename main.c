/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbade <baalbade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:13:14 by baalbade          #+#    #+#             */
/*   Updated: 2022/10/09 17:14:54 by baalbade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <libc.h>
#include "get_next_line.h"

 int main(void)
 {
	 int	fd;
	 char	*line;

	 fd = open("text.txt", O_RDONLY);
	 while (1)
	 {
		 line = get_next_line(fd);
		 printf("%s", line);
		 if (!line)
			 break;
		 free(line);
	 }
	 close(fd);
	 system("leaks a.out");
	 return (0);
 }
 