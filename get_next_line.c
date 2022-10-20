/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:17 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/20 06:28:03 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_read(char *str, int fd, int line_size)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = (char *)malloc(sizeof(char) * (line_size + 1));
	if (tmp == NULL)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && i != 0)
	{
		i = read(fd, tmp, line_size);
		if (i == -1)
		{
			free(tmp);
			free(str);
			return (NULL);
		}
		tmp[i] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free(tmp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*temp;
	int			line_size;

	line_size = BUFFER_SIZE;
	if (fd < 0 || line_size <= 0)
		return (NULL);
	line = get_next_line_read(line, fd, line_size);
	if (!line)
		return (NULL);
	temp = ft_get_line(line);
	line = ft_update_line(line);
	return (temp);
}
