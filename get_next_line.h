#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <sys/types.h>//"open",
#include <sys/stat.h>//"open",
#include <sys/uio.h>//"read"
#include <fcntl.h>//"open",
# include <unistd.h>// "write","close","read"
# include <string.h>// "NULL"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
int	ft_found_n(char *s, int *index)
char	*ft_substr(char const *s, unsigned int start, size_t len)
char	*ft_strjoin(const char *s1, const char *s2)
void	*ft_calloc(size_t count, size_t size)
size_t	ft_strlen(char *s)
char	*ft_strdup(const char *s)
void	read_n_stck(int fd, int *c_read)
void	if_n_found(char *s, int index, char *ligne)

#endif