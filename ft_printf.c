
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvelayut <vvelayut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:54:12 by vvelayut          #+#    #+#             */
/*   Updated: 2022/04/04 19:10:10 by vvelayut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char* str, ...)
{
	int		i;
	char	let;

	i = 0;
	va_list	argptr;
	va_start(argptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				let = va_arg(argptr, int);
				write(1, &let, 1);
			}
			if (*str == 'd')
			{
				let = va_arg(argptr, int) + '0';
				write(1, &let, 1);
			}			
		}
		else
			write(1, str, 1);
		str++;
	}
	va_end(argptr);
	return (0);
}

int	main(void)
{
	ft_printf("Hello this %d is a %c", 6, 'G');
	return (0);
}