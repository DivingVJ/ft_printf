#include "ft_printf.h"
#include "libft/libft.h"

int	check_format(const char *str, va_list argptr)
{
	int		format;
	char	*base;
	char	*cbase;

	base = "0123456789abcdef";
	cbase = "0123456789ABCDEF";
	format = 0;
	if (*str == 'c')
		format = ft_putchar_fd(va_arg(argptr, int), 1);
	if (*str == 's')
		format = ft_putstr_fd(va_arg(argptr, char *), 1);
	if (*str == 'p')
	{
		format = ft_putstr_fd("0x", 1);
		format = format + ft_putnbr_base_fd((unsigned long)va_arg(argptr, void *), base, 1);
	}
	if ((*str == 'd') || (*str == 'i'))
		format = ft_putnbr_fd(va_arg(argptr, int), 1);
	if (*str == 'u')
		format = ft_putunsignbr_fd(va_arg(argptr, unsigned int), 1);
	if (*str == 'x')
		format = ft_putnbr_base_fd(va_arg(argptr, unsigned int), base, 1);
	if (*str == 'X')
		format = ft_putnbr_base_fd(va_arg(argptr, unsigned int), cbase, 1);
	if (*str == '%')
		format = ft_putchar_fd('%', 1);
	return (format);
}
