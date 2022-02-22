/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 18:26:17 by svrielin      #+#    #+#                 */
/*   Updated: 2022/02/22 18:36:39 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_empty_string(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

void	strdelete(char *str)
{
	free(str);
	str = NULL;
}

char	*newline(int fd, char **saved, int bytes_read)
{
	char	*line;
	char	*tmp;
	int		len;
	if ((ft_strchr(saved[fd], '\n')))
	{
		tmp = (ft_strchr(saved[fd], '\n') + 1);
		len = ft_strlen(saved[fd]) - ft_strlen(tmp);
		line = ft_strndup(saved[fd], len);
		strdelete(saved[fd]);
		saved[fd] = ft_strdup(tmp);
		return (line);
	}
	if (bytes_read < BUFFER_SIZE)
	{
		if (bytes_read == 0 && saved[fd][0] == '\0')
			return (NULL);
		line = ft_strdup(saved[fd]);
		strdelete(saved[fd]);
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
	while (!ft_strchr(saved[fd], '\n') && bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			strdelete(saved[fd]);
			return (0);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_gnlstrjoin(saved[fd], buffer);
		if (tmp == NULL)
			return (0);
		saved[fd] = ft_strdup(tmp);
		strdelete(tmp);
	}
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		*line;
	int			bytes_read;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved[fd])
	{
		saved[fd] = create_empty_string();
		if (saved[fd] == NULL)
			return (NULL);
	}
	bytes_read = readtillnewline(fd, saved);
	if (bytes_read == 0)
		return (NULL);
	line = newline(fd, saved, bytes_read);
	return (line);
}
