/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:32:17 by carmoliv          #+#    #+#             */
/*   Updated: 2025/05/15 19:34:16 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	assist_pointer(unsigned long ptr)
{
	int			count;
	char		*base;

	count = 0;
	base = "0123456789abcdef";
	if (ptr >= 16)
		count += assist_pointer(ptr / 16);
	count += printf_putchar(base[ptr % 16]);
	return (count);
}

int	printf_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += assist_pointer((unsigned long)ptr);
	return (count);
}
