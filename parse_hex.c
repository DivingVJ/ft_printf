#include "ft_printf.h"
#include "libft/libft.h"

int	parse_hex(unsigned long ulong, char type)
{
	int		len;
	char	*base;
	char	*cbase;

	base = "0123456789abcdef";
	cbase = "0123456789ABCDEF";
	len = 0;
	if (type == 'p')
	{
		len = ft_putstr_fd("0x", 1);
		len = len + ft_putnbr_b_fd(ulong, base, 1);	
	}
	if (type == 'x')
		len = ft_putnbr_b_fd(ulong, base, 1);
	if (type == 'X')
		len = ft_putnbr_b_fd(ulong, cbase, 1);
	return (len);
}
