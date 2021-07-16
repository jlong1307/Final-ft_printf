/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_untils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 18:08:25 by jlong             #+#    #+#             */
/*   Updated: 2021/07/16 09:41:14 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
	{
		write(1, str++, 1);

	}
}

void	ft_putchar(char c, t_format* format_len)
{
	write(1, &c ,1);
	format_len->size = format_len->size +1;
}