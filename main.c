/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 10:05:45 by svrielin      #+#    #+#                 */
/*   Updated: 2022/02/24 20:16:59 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h> 

// void checkleaks()
// {
//     system("leaks a.out");
// }

// int	main(void)
// {
// 	char	*line;
// 	int		fd;
// 	//int		fd1;
	
// 	fd = open("nl", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("Return get next line = %s\n", line);
// 	free (line);

// 	/* 
// 	fd = open("bible.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("Return get next line = %s\n", line);
// 	free (line);
// 	while (line)
// 	{
// 		line = get_next_line(fd);
// 		printf("Return get next line = %s\n", line);
// 	}

// 	fd1 = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd1);
// 	printf("Return get next line = %s\n", line);
// 	free (line);
// 	while (line)
// 	{
// 		line = get_next_line(fd1);
// 		printf("Return get next line = %s\n", line);
// 		free (line);
// 	}
// 	line = get_next_line(fd);
// 	printf("Return get next line = %s\n", line);
// 	free (line);

// 	line = get_next_line(fd1);
// 	printf("Return get next line = %s\n", line);
// 	free (line);*/
// 	// atexit(checkleaks);
// }

int main() {
	char* line;
	int fd = 43; //!!!!!!!!!!!!!! DIT CHECKEN
	if (fd == -1)
		fd = 0;
	do {
		line = get_next_line(fd);
		printf("line=%s\n", line);
		free(line);
	} while (line != NULL);
	// system("leaks a.out");
	return (0);
}