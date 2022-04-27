/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvelayut <vvelayut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:00:29 by vvelayut          #+#    #+#             */
/*   Updated: 2022/04/27 12:03:40 by vvelayut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

char	check_format(const char *str, va_list argptr)
{
	char			format;
	int				num;
	char*			word;

	format = '\0';
	if (*str == 'c')
	{

	}
		if (*str == 's')
	{
		word = va_arg(argptr, char*);
		ft_putstr_fd(word, 1);
	}
	if ((*str == 'd') || (*str == 'i'))
	{
		num = va_arg(argptr, int);
		ft_putnbr_fd(num, 1);
	}	
	if (*str == 'u')
	{
//		unum = va_arg(argptr, int);
		ft_putunsignbr_fd(va_arg(argptr, int), 1);
	}		
	if (*str == '%')
	{
		write(1, "%", 1);
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
