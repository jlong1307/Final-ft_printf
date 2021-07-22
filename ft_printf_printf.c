/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:17:39 by jlong             #+#    #+#             */
/*   Updated: 2021/07/22 14:54:35 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printfh.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c, t_format *format_len)
{
	write(1, &c, 1);
	format_len->size = format_len->size +1;
}

void	print_char(va_list ap, t_format *format_len)
{
	unsigned char	x;

	x = va_arg(ap, int);
	ft_putchar(x, format_len);
}

void	print_str(va_list ap, t_format *format_len)
{
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)va_arg(ap, const char *);
	ret = ft_strlen(tmp);
	while (i < ret)
	{
		ft_putchar(tmp[i++], format_len);
	}
}
