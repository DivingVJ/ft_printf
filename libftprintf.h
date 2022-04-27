#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

/* typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list; */

/* Mandatory */
int		ft_printf(const char* str, ...);

#endif