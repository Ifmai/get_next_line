/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:12 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/20 06:52:00 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_update_line(char *str)
{
	int		i;
	int		j;
	char	*back;

	i = 0;
	j = -1;
	while (str[i] != '\n' && str[i])
		i++;
	if (!*(str + i))
	{
		free(str);
		return (NULL);
	}
	back = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!back)
		return (NULL);
	i++;
	while (str[i])
	{
		back[++j] = str[i];
		i++;
	}
	back[++j] = '\0';
	free(str);
	return (back);
}

char	*ft_get_line(char *str)
{
	char	*rtn;
	int		i;

	i = 0;
	if (!*(str + i))
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	rtn = malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		rtn[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		rtn[i] = '\n';
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *str2)
{
	char	*back;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!str)
	{
		str = malloc(1 * sizeof(char));
		*str = '\0';
	}
	back = malloc((ft_strlen(str) + ft_strlen(str2) + 1) * sizeof(char));
	if (!back)
		return (NULL);
	while (str[i])
	{
		back[i] = str[i];
		i++;
	}
	while (str2[++j])
		*(back + i + j) = *(str2 + j);
	*(back + i + j) = '\0';
	free(str);
	return (back);
}
