#include "ft_printf.h"
#include "libft/libft.h"

int	check_format(const char *str, va_list argptr)
{
	int		len;

	len = 0;
	if (*str == 'c')
		len = ft_putchar_fd(va_arg(argptr, int), 1);
	if (*str == 's')
		len = ft_putstr_fd(va_arg(argptr, char *), 1);
	if (*str == 'p')
		len = len + parse_hex((unsigned long)va_arg(argptr, void *), *str);
	if ((*str == 'd') || (*str == 'i'))
		len = ft_putnbr_fd(va_arg(argptr, int), 1);
	if (*str == 'u')
		len = ft_putunsignbr_fd(va_arg(argptr, unsigned int), 1);
	if ((*str == 'x') || (*str == 'X'))
		len = parse_hex(va_arg(argptr, unsigned int), *str);
	if (*str == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}
