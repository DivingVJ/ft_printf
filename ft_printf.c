#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	int		num;
	va_list	argptr;
	int		count;
	int		total;

	num = 0;
	count = 0;
	total = 0;
	va_start(argptr, str);
	while (*str)
	{
		if ((*str == '%') && (*str + 1 != '\0'))
		{
			str++;
			count = check_format(str, argptr);
		}
		else
			num = num + write(1, str, 1);
		total = total + count;
		count = 0;
		str++;
	}
	va_end(argptr);
	return (num + total);
}
