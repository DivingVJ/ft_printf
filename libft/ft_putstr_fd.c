#include "libft.h"

/* putstr_fd - opens an external file and writes in  string s */
/* Protected - null *c */
void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	if (fd == -1 || c == NULL)
		return ;
	while (c[i] != '\0')
	{
		write(fd, &c[i], 1);
		i++;
	}
}
