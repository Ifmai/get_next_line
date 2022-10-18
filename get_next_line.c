/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:15:17 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/18 16:17:54 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line_read(char *str, int fd ,int line_size)
{
	char *tmp;
	int i;

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


char *get_next_line(int fd)
{
	static char *line;
	char *temp;
	int line_size;

	line_size = BUFFER_SIZE;
	line = malloc(sizeof(char) * (line_size + 1));
	if(!line)
		return (NULL);
	if (fd < 0 || line_size <= 0)
		return (NULL);
	line = get_next_line_read(line, fd, line_size);
	if (line == NULL)
		return (NULL);
	temp = ft_new_line(line);
	line = ft_update_line(line);
	return (temp);
}

int main()
{
	int fd;
	char *line;
	int i = 0;
	fd = open("get_next_line.h", O_RDONLY);
	while(i < 5)
	{
		line = get_next_line(fd);
		printf("\n%s", line);
		i++;
	}
	return (0);
}