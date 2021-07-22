/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_untils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:08:25 by jlong             #+#    #+#             */
/*   Updated: 2021/07/22 14:54:37 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfh.h"

void	ft_putnbr(long long nbr, t_format *format_len)
{
	if (nbr < 0)
	{
		ft_putchar('-', format_len);
		ft_putnbr(nbr * -1, format_len);
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar('0' + nbr, format_len);
	else
	{
		ft_putnbr(nbr / 10, format_len);
		ft_putnbr(nbr % 10, format_len);
	}
}

void	ft_conver_x(unsigned long nbr, t_format *format_len)
{
	char	*base;

	base = "0123456789abcdef";
	 if (nbr <= 15)
		ft_putchar(nbr[base], format_len);
	else
	{
		ft_conver_x(nbr / 16, format_len);
		ft_conver_x(nbr % 16, format_len);
	}
}
