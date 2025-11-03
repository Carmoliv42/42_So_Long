/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmoliv <carmoliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 20:43:50 by carmoliv          #+#    #+#             */
/*   Updated: 2025/05/15 19:39:44 by carmoliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	printf_putchar(char c);
int	printf_putstr(char *s);
int	printf_pointer(void *ptr);
int	printf_hex(unsigned int num, int up_lw);
int	printf_unsigned_int(unsigned int n);
int	printf_int(int num);

#endif