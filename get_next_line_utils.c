/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:12 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 16:14:41 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_update_line(char *str)
{
	int		i;
	char	*back;
	int j;

	if(str[0] == 0)
		return NULL;
	i = 0;
	j = 0;
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	back = malloc(sizeof(char) * (ft_strlen(str) - i) + 1);
	i++;
	while(str[i] != '\0')
	{
		back[j] = str[i];
		j++;
		i++;
	}
	back[j] = '\0';
	return (back);
}
char *ft_new_line(char *str)
{
	int 	i;
	char 	*rtn;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (rtn == NULL)
		return (NULL);
	i = 0;
	while(str[i] != '\n' && str[i] != '\0')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == s[i])
		return ((char *)(s + i));
	return (0);
}

size_t ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *str, char *str2)
{
	char	*back;
	size_t	i;

	i = 0;
	back = malloc((ft_strlen(str) + ft_strlen(str2)) * sizeof(char) + 1);
	if (!back)
		return (0);
	while(*(str+i))
	{
		*(back + i) = *(str+i);
		i++;
	}
	while(*(str2 + i))
	{
		*(back + i) = *(str2 + i);
		i++;
	}
	*(back + i) = '\0';
	free(str);
	return (back);
}