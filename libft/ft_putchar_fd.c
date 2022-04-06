#include "libft.h"

/* putchar_fd - opens an external file and writes in character c */
void	ft_putchar_fd(char c, int fd)
{
	if (fd == -1)
		return ;
	write(fd, &c, 1);
}
