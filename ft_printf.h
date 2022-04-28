#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

/* Mandatory */
int		ft_printf(const char* str, ...);
int		check_format(const char *str, va_list argptr);
#endif