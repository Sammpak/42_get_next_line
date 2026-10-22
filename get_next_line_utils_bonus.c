/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spaccaud <spaccaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/19 14:00:25 by spaccaud          #+#    #+#             */
/*   Updated: 2026/10/22 10:30:58 by spaccaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_lengh;
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	total_lengh = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (total_lengh + 1));
	if (str == NULL)
		return (free(s1), NULL);
	while (s1 && s1[j])
	{
		str[i] = s1[j];
		j++;
		i++;
	}
	while (*s2)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (free(s1), str);
}

int	ft_strlen(const char *str)
{
	int	result;

	if (str == NULL)
		return (0);
	result = 0;
	while (str[result] != '\0')
		result++;
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;
	char			*res;

	if (s == NULL)
		return (NULL);
	uc = (unsigned char)c;
	res = (char *)s;
	if (uc == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*res)
	{
		if (*res == uc)
			return (res);
		res++;
	}
	return (NULL);
}
