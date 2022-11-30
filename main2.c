#include <stdio.h>
#include <fcntl.h>
// #include <libc.h>
#include "get_next_line.h"

 int main(void)
 {
	 int	fd;
	 int	fd2;
	 char	*line;

	 fd = open("text.txt", O_RDONLY);
	 fd2 = open("text.txt", O_RDONLY);

	 while (1)
	 {
		 line = get_next_line(fd);
		 printf("%s", line);
		 if (!line)
			 break;
		 free(line);
		 line = get_next_line(fd2);
		 printf("%s", line);
		 if (!line)
			 break;
		 free(line);
	 }
	 close(fd);
	//  system("leaks a.out");
	 return (0);
 }
