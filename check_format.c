#include "ft_printf.h"
#include "libft/libft.h"

int	check_format(const char *str, va_list argptr)
{
	int		len;
	char	*base;
	char	*cbase;

	base = "0123456789abcdef";
	cbase = "0123456789ABCDEF";
	len = 0;
	if (*str == 'c')
		len = ft_putchar_fd(va_arg(argptr, int), 1);
	if (*str == 's')
		len = ft_putstr_fd(va_arg(argptr, char *), 1);
	if (*str == 'p')
		len += ft_putnbr_b_fd((unsigned long)va_arg(argptr, void *), base, 1);
	if ((*str == 'd') || (*str == 'i'))
		len = ft_putnbr_fd(va_arg(argptr, int), 1);
	if (*str == 'u')
		len = ft_putunsignbr_fd(va_arg(argptr, unsigned int), 1);
	if (*str == 'x')
		len = ft_putnbr_b_fd(va_arg(argptr, unsigned int), base, 1);
	if (*str == 'X')
		len = ft_putnbr_b_fd(va_arg(argptr, unsigned int), cbase, 1);
	if (*str == '%')
		len = ft_putchar_fd('%', 1);
	return (len);
}
