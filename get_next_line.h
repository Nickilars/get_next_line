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

typedef struct s_list	t_list;
struct s_list
{
	char			*content;
	struct s_list	*next;
};

char	*get_next_line(int fd);

#endif