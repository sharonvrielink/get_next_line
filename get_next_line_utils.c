/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: svrielin <svrielin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/22 18:26:03 by svrielin      #+#    #+#                 */
/*   Updated: 2022/02/24 18:03:27 by svrielin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s2 = (char *)malloc((ft_strlen (s1) + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char *)malloc((n + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s != (char)c)
			s++;
		else
			return ((char *)s);
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_gnlstrjoin(char *s1, char *s2)
{
	char	*joinedstr;
	int		i;
	int		j;
	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	joinedstr = (char *)malloc((ft_strlen (s1) + ft_strlen (s2) + 1)* sizeof(char));
	if (!joinedstr)
		return (NULL);
	while (s1[i] != '\0')
	{
		joinedstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		joinedstr[i] = s2[j];
		i++;
		j++;
	}
	joinedstr[i] = '\0';
	return (joinedstr);
}
