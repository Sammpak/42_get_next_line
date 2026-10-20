	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2026/10/19 13:58:29 by spaccaud          #+#    #+#             */
	/*   Updated: 2026/10/20 15:22:57 by spaccaud         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "get_next_line.h"

	char	*write_stash(int fd, char *stash)
	{
		char	*buffer;
		int		n;

		n = 1;
		buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		while (ft_strchr(stash, '\n') == NULL && n > 0)
		{
			n = read(fd, buffer, BUFFER_SIZE);
			buffer[n] = '\0';
			stash = ft_strjoin(stash, buffer);
		}
		free(buffer);
		return (stash);
	}

	char	*ft_result_maker(int len, char *stash)
	{
		char	*result;
		int		k;

		k = 0;
		result = malloc(sizeof(char *) * len + 1);
		if (result == NULL)
			return (NULL);
		while (k < len)
		{
			result[k] = stash[k];
			k++;
		}
		result[k] = '\0';
		return (result);
	}

	char	*ft_reset_stash(int len, char *stash)
	{
		int	h;

		h = 0;
		len++;
		while (stash[len])
		{
			stash[h] = stash[len];
			h++;
			len++;
		}
		stash[h] = '\0';
		return (stash);
	}

	char	*get_next_line(int fd)
	{
		char static	*stash;
		char		*result;
		int			i;
		int			j;
		int			len;

		stash = write_stash(fd, stash);
		i = 0;
		while (stash[i])
		{
			if (stash[i] == '\n')
			{
				j = i;
				while (stash[j])
					j++;
				len = ft_strlen(stash) - (j - i);
				result = ft_result_maker(len, stash);
				stash = ft_reset_stash(len, stash);
				return (result);
			}
			i++;
		}
		if (stash[0] != '\0')
		{
			result = ft_result_maker(ft_strlen(stash), stash);
			free(stash);
			stash = NULL;
			return (result);
		}
		free(stash);
		stash = NULL;
		return (NULL);
	}

	int	main(void)
	{
		char	*filename;
		int		fd;
		char	*result;

		filename = "test.txt";
		fd = dict_open(filename, O_RDONLY);
		if (fd == 0)
			return (0);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		printf("[%s]\n", result);
		result = get_next_line(fd);
		dict_close(fd);
		return (0);
	}
