#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char *get_next_line(int fd);
char *get_next_line_read(char *str, int fd ,int line_size);
char	*ft_strchr(char *s, int c);
size_t ft_strlen(char *s);
char *ft_strjoin(char *str, char *str2);
char *ft_new_line(char *str);
char *ft_update_line(char *str);

#endif