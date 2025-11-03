/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:31:08 by carmoliv          #+#    #+#             */
/*   Updated: 2025/05/15 19:32:01 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_unsigned_int(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += printf_unsigned_int(n / 10);
	count += printf_putchar((n % 10) + '0');
	return (count);
}
