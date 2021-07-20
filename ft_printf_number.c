/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 18:37:41 by jlong             #+#    #+#             */
/*   Updated: 2021/07/20 18:37:55 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_int(va_list ap, t_format *format_len)
{
	long long	nbrconv;

	nbrconv = va_arg(ap, int);
	ft_putnbr(nbrconv, format_len);
}

void	printf_u(va_list ap, t_format *format_len)
{
	unsigned long	nbrconv;

	nbrconv = va_arg(ap, unsigned int);
	if (nbrconv >= 0 && nbrconv <= 9)
		ft_putchar('0' + nbrconv, format_len);
	else
	{
		ft_putnbr(nbrconv / 10, format_len);
		ft_putnbr(nbrconv % 10, format_len);
	}
}

void	printf_pointer(va_list ap, t_format *format_len)
{
	unsigned long	nbrconv;

	nbrconv = (unsigned long)va_arg(ap, void *);
	ft_putchar('0', format_len);
	ft_putchar('x', format_len);
	ft_conver_x(nbrconv, format_len);
}

void	printf_x(va_list ap, t_format *format_len)
{
	unsigned long	nbrconv;

	nbrconv = (unsigned long)va_arg(ap, unsigned int);
	ft_conver_x(nbrconv, format_len);
}
