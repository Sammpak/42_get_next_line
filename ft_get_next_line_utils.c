/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:00:25 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/19 14:35:04 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	dict_open(char *file, int __oflag)
{
	int	fd;

	fd = open(file, __oflag);
	if (fd == -1)
		return (0);
	return (fd);
}

int	dict_close(int filedesc)
{
	if (close(filedesc) == -1)
		return (1);
	return (0);
}
