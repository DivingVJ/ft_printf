
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

int	ft_printf(const char*, ...);

int	main(void)
{
	printf("Testing Variadic Functions\n");
	ft_printf("Hello");
	return (0);
}

int	ft_printf(const char*, ...)
{
	int		i;
	va_list	argptr;

	i = 0;
	va_start(argptr, number);
	printf("number = %d \n", number);
	while (i < number)
	{
		printf("Numbers %d \n", va_arg(argptr, int));
		i = i + 1;
	}
	va_end(argptr);
	return (0);
}


/* Cases to consider:
Full text, string or character
Number base 10
Number Hex
Pointer address
Combination of both
*/

