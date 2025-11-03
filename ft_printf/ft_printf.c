/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:48:24 by carmoliv          #+#    #+#             */
/*   Updated: 2025/05/16 21:00:56 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_printf(const char parameter, va_list arg)
{
	int	i;

	i = 0;
	if (parameter == 'c')
		i += printf_putchar(va_arg(arg, int));
	else if (parameter == 's')
		i += printf_putstr(va_arg(arg, char *));
	else if (parameter == 'p')
		i += printf_pointer(va_arg(arg, void *));
	else if (parameter == 'd')
		i += printf_int(va_arg(arg, int));
	else if (parameter == 'i')
		i += printf_int(va_arg(arg, int));
	else if (parameter == 'u')
		i += printf_unsigned_int(va_arg(arg, int));
	else if (parameter == 'x')
		i += printf_hex(va_arg(arg, int), 0);
	else if (parameter == 'X')
		i += printf_hex(va_arg(arg, int), 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		l_parameter;
	int			count;

	count = 0;
	va_start (l_parameter, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c' || *format == 's' || *format == 'p'
				|| *format == 'd' || *format == 'i' || *format == 'u'
				|| *format == 'x' || *format == 'X')
				count += check_printf(*format, l_parameter);
			else if (*format == '%')
				count += printf_putchar('%');
		}
		else
			count += printf_putchar(*format);
		format++;
	}
	va_end (l_parameter);
	return (count);
}
/* #include <stdio.h>
int	main()
{
	printf("%d \n", ft_printf("%p ", 291));
	write(1, "\n", 1);
	printf("%d \n", printf("%d ", 291));
} */
