/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hozdemir <hozdemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:29:47 by hozdemir          #+#    #+#             */
/*   Updated: 2022/10/20 06:30:16 by hozdemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 31
# endif

char	*get_next_line(int fd);
char	*get_next_line_read(char *str, int fd, int line_size);
int		ft_strchr(char *s, int c);
int		ft_strlen(char *s);
char	*ft_strjoin(char *str, char *str2);
char	*ft_get_line(char *str);
char	*ft_update_line(char *str);

#endif