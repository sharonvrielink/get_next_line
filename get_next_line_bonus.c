/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 18:26:17 by svrielin      #+#    #+#                 */
/*   Updated: 2021/09/23 15:42:16 by svrielin      ########   odam.nl         */
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

void	strdelete(char **str, int fd)
{
	free(str[fd]);
	str[fd] = create_empty_string();
}

char	*newline(int fd, char **saved, int b_read)
{
	char	*line;
	char	*tmp;
	int		len;

	len = (ft_strlen(saved[fd]));
	if ((ft_strchr(saved[fd], '\n')))
	{
		tmp = (ft_strchr(saved[fd], '\n') + 1);
		len = ft_strlen(saved[fd]) - ft_strlen(tmp);
		line = ft_strndup(saved[fd], len);
		free (saved[fd]);
		saved[fd] = ft_strdup(tmp);
		return (line);
	}
	if (b_read < BUFFER_SIZE)
	{
		if (b_read == 0 && saved[fd][0] == '\0')
			return (NULL);
		line = ft_strdup(saved[fd]);
		strdelete(saved, fd);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*saved[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			b_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b_read = BUFFER_SIZE;
	if (!saved[fd])
		saved[fd] = create_empty_string();
	while (!ft_strchr(saved[fd], '\n') && b_read == BUFFER_SIZE)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = '\0';
		saved[fd] = ft_gnlstrjoin(saved[fd], buffer);
	}
	line = newline(fd, saved, b_read);
	return (line);
}
