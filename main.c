/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 10:05:45 by svrielin      #+#    #+#                 */
/*   Updated: 2022/02/22 13:13:11 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> 

void checkleaks()
{
    system("leaks a.out");
}

int	main(void)
{
	char	*line;
	int		fd;
	//int		fd1;
	
	fd = open("nolinetest.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Return get next line = %s\n", line);
	free (line);

	/* 
	fd = open("bible.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Return get next line = %s\n", line);
	free (line);
	while (line)
	{
		line = get_next_line(fd);
		printf("Return get next line = %s\n", line);
	}

	fd1 = open("test.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("Return get next line = %s\n", line);
	free (line);
	while (line)
	{
		line = get_next_line(fd1);
		printf("Return get next line = %s\n", line);
		free (line);
	}
	line = get_next_line(fd);
	printf("Return get next line = %s\n", line);
	free (line);

	line = get_next_line(fd1);
	printf("Return get next line = %s\n", line);
	free (line);*/
	atexit(checkleaks);
}
