/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:58:29 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/22 10:33:21 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*write_stash(int fd, char *stash)
{
	char	*buffer;
	int		n;

	n = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free(stash), NULL);
	while (ft_strchr(stash, '\n') == NULL && n > 0)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(stash), free(buffer), NULL);
		buffer[n] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*ft_result_maker(int len, char *stash)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = stash[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_reset_stash(int len, char *stash)
{
	int	h;

	h = 0;
	while (stash[len])
	{
		stash[h] = stash[len];
		h++;
		len++;
	}
	stash[h] = '\0';
	return (stash);
}

char	*check_line(char *stash)
{
	char	*result;
	int		i;
	int		len;

	i = 0;
	len = 0;
	result = NULL;
	while (stash[i])
	{
		if (stash[i] == '\n')
		{
			len = i + 1;
			result = ft_result_maker(len, stash);
			stash = ft_reset_stash(len, stash);
			return (result);
		}
		i++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*result;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = write_stash(fd, stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	result = check_line(stash[fd]);
	if (result)
		return (result);
	if (stash[fd][0] != '\0')
	{
		result = ft_result_maker(ft_strlen(stash[fd]), stash[fd]);
		free(stash[fd]);
		stash[fd] = NULL;
		return (result);
	}
	free(stash[fd]);
	stash[fd] = NULL;
	return (NULL);
}
