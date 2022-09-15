/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 18:26:17 by svrielin      #+#    #+#                 */
/*   Updated: 2022/09/15 19:30:14 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // TODO: REMOVE

char	*create_empty_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

char *strdelete(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*newline(int fd, char **saved, int bytes_read)
{
	char	*line;
	char	*tmp;
	int		len;
	if ((ft_strchr(saved[fd], '\n')))
	{
		tmp = ft_strdup((ft_strchr(saved[fd], '\n') + 1));
		if (tmp == 0)
			return (NULL);
		len = ft_strlen(saved[fd]) - ft_strlen(tmp);
		line = ft_strndup(saved[fd], len);
		strdelete(saved[fd]);
		saved[fd] = ft_strdup(tmp);
		strdelete(tmp);
		return (line);
	}
	if (bytes_read < BUFFER_SIZE)
	{
		if (bytes_read == 0 && saved[fd][0] == '\0')
			return (NULL);
		line = ft_strdup(saved[fd]);
		saved[fd] = strdelete(saved[fd]);
		//saved[fd] = NULL;
		return (line);
	}
	return (NULL);
}

int	readtillnewline(int fd, char **saved)
{
	char	*tmp;
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	bytes_read = BUFFER_SIZE;
	while (!ft_strchr(saved[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (0);
		if (bytes_read == -1)
		{
			strdelete(saved[fd]);
			return (0);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_gnlstrjoin(saved[fd], buffer);
		if (tmp == NULL)
			return (0);
		strdelete(saved[fd]);
		saved[fd] = ft_strdup(tmp);
		if (saved[fd] == NULL)
			return (0);
		strdelete(tmp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		*line;
	int			bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0 || read())
		return (NULL);
	if (!saved[fd])
		saved[fd] = create_empty_string();
	if (saved[fd] == NULL)
		return (NULL);
	bytes_read = readtillnewline(fd, saved);
	line = newline(fd, saved, bytes_read);
	if (line == NULL)
	{
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}
