/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:17:39 by jlong             #+#    #+#             */
/*   Updated: 2021/07/16 15:34:27 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n <= 9)
		return (1);
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

void	ft_putnbr(long long nbr, t_format* format_len)
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

void	print_char(va_list ap, t_format* format_len)
{
	unsigned x;

	x = va_arg(ap, int);
	ft_putchar(x, format_len);
}

void	print_str(va_list ap, t_format* format_len)
{
	int 	ret;
	int		i;
	char	*tmp;

	i = 0;
	tmp = va_arg(ap, char *);
	ret = ft_strlen(tmp);
	while (i < ret)
	{
		ft_putchar(tmp[i++], format_len);
	}
}

void	print_int(va_list ap, t_format* format_len)
{
	long long	nbrconv;

	nbrconv = va_arg(ap, int);
	ft_putnbr(nbrconv, format_len);
}
//putnbre avec unsigned long sans négatif 
void	printf_u(va_list ap, t_format* format_len)
{
	unsigned long nbrconv;

	nbrconv = va_arg(ap, unsigned int);
	if (nbrconv >= 0 && nbrconv <= 9)
		ft_putchar('0' + nbrconv, format_len);
	else
	{
		ft_putnbr(nbrconv / 10, format_len);
		ft_putnbr(nbrconv % 10, format_len);
	}
}
// transformation héxade
void	printf_pointer(va_list ap, t_format* format_len)
{
	unsigned long nbrconv;
	nbrconv = (unsigned long)va_arg(ap, void *);
}

void	printf_x(va_list ap, t_format* t_format_len)
{
	unsigned long nbrconv;
	nbrconv = va_arg(ap, unsigned int);
}
