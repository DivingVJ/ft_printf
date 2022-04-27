/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvelayut <vvelayut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:00:29 by vvelayut          #+#    #+#             */
/*   Updated: 2022/04/27 16:42:55 by vvelayut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	check_format(const char *str, va_list argptr)
{
	int			format;
	int				num;
	char*			word;
	unsigned long 	ulong;

	format = 0;
	if (*str == 'c')
	{
		num = va_arg(argptr, int);
		format = ft_putchar_fd(num, 1);
	}
		if (*str == 's')
	{
		word = va_arg(argptr, char*);
		format = ft_putstr_fd(word, 1);
	}
	if ((*str == 'd') || (*str == 'i'))
	{
		num = va_arg(argptr, int);
		format = ft_putnbr_fd(num, 1);
	}	
	if (*str == 'u')
	{
		format = ft_putunsignbr_fd(va_arg(argptr, unsigned int), 1);
	}
	if (*str == 'p')
	{
		ulong = va_arg(argptr,unsigned long);
		format = ft_putstr_fd("0x", 1);
		format = format + ft_putunsignbr_fd(ulong, 1);
	}
	if (*str == 'x')
	{
		num = va_arg(argptr, int);
		format = ft_putnbr_base_fd(num, "0123456789abcdef", 1);
	}		
	if (*str == '%')
	{
		write(1, "%", 1);
		format = format + 1;
	} 
	return (format);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		num;
	va_list	argptr;
	int		count;
	int		total;

	i = 0;
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
		{
			write(1, str, 1);
			num = num + 1;
		}
		total = total + count;
		count = 0;
		str++;
	}
	va_end(argptr);
	return (num+ total);
}
