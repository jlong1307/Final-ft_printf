/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:41:44 by jlong             #+#    #+#             */
/*   Updated: 2021/07/20 16:51:32 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_conv(va_list ap, const char *str, t_format *format_len)
{
	str++;
	if (*str == '%')
	{
		write (1, "%", 1);
		format_len->size = format_len->size + 1;
	}
	else if (*str == 'c')
		print_char(ap, format_len);
	else if (*str == 's')
		print_str(ap, format_len);
	else if (*str == 'i' || *str == 'd')
		print_int(ap, format_len);
	else if (*str == 'u')
		printf_u(ap, format_len);
	else if (*str == 'p')
		printf_pointer(ap, format_len);
	else if (*str == 'x')
		printf_x(ap, format_len);
}

int	ft_readerprintf(va_list ap, const char *format, t_format *format_len)
{
	while (*format)
	{
		if (*format == '%')
		{
			ft_check_conv(ap, format, format_len);
			*format++;
		}
		else if (*format - 1 != '%')
			ft_putchar(*format, format_len);
		*format++;
	}
	return (format_len->size);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_format	format_len;

	format_len.size = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	count = ft_readerprintf(ap, format, &format_len);
	va_end(ap);
	return (count);
}
