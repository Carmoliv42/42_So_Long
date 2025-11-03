/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:34:32 by carmoliv          #+#    #+#             */
/*   Updated: 2025/05/15 19:34:40 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_int(int num)
{
	long	x;
	long	result;

	result = 0;
	x = num;
	if (num < 0)
	{
		result += printf_putchar('-');
		x = -x;
	}
	if (x > 9)
		result += printf_int(x / 10);
	result += printf_putchar((x % 10) + '0');
	return (result);
}
