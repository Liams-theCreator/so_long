/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:28:46 by imellali          #+#    #+#             */
/*   Updated: 2025/03/02 18:15:46 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*buffer;

	i = 0;
	len = ft_strlen(s);
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		buffer[i] = s[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static void	freeing(char **buf)
{
	free(*buf);
	*buf = NULL;
}

static char	*reading(int fd, char *buf, char *temp)
{
	int		byter;
	char	*pt;

	byter = read(fd, temp, BUFFER_SIZE);
	while (byter > 0)
	{
		temp[byter] = '\0';
		pt = buf;
		buf = ft_strjoin(buf, temp);
		freeing(&pt);
		if ((ft_strchr(buf, '\n')))
			break ;
		byter = read(fd, temp, BUFFER_SIZE);
	}
	if (byter == -1)
	{
		freeing(&buf);
		return (NULL);
	}
	return (buf);
}

static char	*nlcheck(char **leftover, char *temp)
{
	char	*newline;
	char	*data;
	char	*pt;

	newline = ft_strchr(*leftover, '\n');
	if (newline)
	{
		data = ft_substr(*leftover, 0, newline - *leftover + 1);
		if (!data)
			return (NULL);
		pt = *leftover;
		*leftover = ft_strdup(newline + 1);
		freeing(&pt);
		freeing(&temp);
		return (data);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*leftover[1024];
	char		*temp;
	char		*newline;
	char		*data;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	leftover[fd] = reading(fd, leftover[fd], temp);
	if (!leftover[fd] || *leftover[fd] == '\0')
	{
		freeing(&leftover[fd]);
		freeing(&temp);
		return (NULL);
	}
	newline = nlcheck(&leftover[fd], temp);
	if (newline)
		return (newline);
	data = ft_strdup(leftover[fd]);
	freeing(&leftover[fd]);
	freeing(&temp);
	return (data);
}
