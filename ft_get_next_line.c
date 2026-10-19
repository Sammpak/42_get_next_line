/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 13:58:29 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/19 15:57:35 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	static	char *buffer;
	static int i;

	if(!(i != 0))
		i = 0;
	printf(" i value %d  \n", i);
	buffer = malloc(sizeof(char *) * 200);
	if(buffer == NULL)
		return NULL;

	int n = read(fd, buffer, BUFSIZ);
	while(i < n && buffer[i] != '\n')
	{
		printf("%c", buffer[i]);
		i++;
	}
	i++;
	free(buffer);
	return NULL;
}


int main()
{
	char *filename = "test.txt";
	int fd = dict_open(filename, O_RDONLY);
	if(fd == 0)
		return (0);
		
	get_next_line(fd); // first line
	get_next_line(fd); // second line
	return (0);
}
