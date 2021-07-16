/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 14:41:44 by jlong             #+#    #+#             */
/*   Updated: 2021/07/16 15:34:26 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf_istype(int c)
{
	return (c == 's'|| c == 'p' || c == 'd'||
			c == 'i'|| c == 'u'|| c == 'x' ||
			c == 'c' || c == '%');
}

void	ft_check_conv(va_list ap, const char *str, t_format* format_len)
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

int	ft_readerprintf(va_list ap, const char *format, t_format* format_len)
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
	return(format_len->size);
}
 
int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	t_format 	format_len;
	
	format_len.size = 0;
	if (!format)
		return (-1);
	va_start(ap, format);
	count = ft_readerprintf(ap, format, &format_len);
	va_end(ap);
	return (count);
}

int	main(void)
{
	int nbr1, nbr2;
	nbr1 = 0;
	nbr2 = 0;
	//TEST POUR %%
	printf("test pour le pourcentagex2\n");
	nbr1 = ft_printf("%%lol %%mdr----->mon printf\n");
	nbr2 = printf("%%lol %%mdr---->vrai printf\n");
	printf("%i---%i\n", nbr1, nbr2);
	//TEST POUR c
	printf("test pour char\n");
	int nbr3, nbr4;
	nbr3 = ft_printf("mon printf = %c\n", 'a');
	nbr4 = printf("vrai printf =%c\n", 'a');
	printf("%i---%i\n", nbr3, nbr4);
	//TEST POUR s et c
	printf("test pour string\n");
	char chaine[] = "j'aime les pommes et les banane";
	int nbr5, nbr6;
	nbr5 = ft_printf("mon printf = %s hello %c\n", chaine, 'a');
	nbr6 = printf("vrai printf =%s hello %c\n", chaine, 'a');
	printf("%i---%i\n", nbr5, nbr6);
	//TEST POUR i et d
	printf("test pour l int en décimal signé i et d\n");
	int nbr11, nbr12, nbr13, nbr14;
	nbr11 = ft_printf("mon printf : mon nombre est le %i et le deuxieme %d\n", 55, -55);
	nbr12 = printf("vrai printf :mon nombre est le %i et le deuxieme %d\n", 55, -55);
	printf("%i---%i\n", nbr11, nbr12);
	nbr13 = ft_printf("nombre min_int %i | %d et max_int %i | %d\n",-2147483647, -2147483647, 2147483647, 2147483647);
	nbr14 = printf("nombre min_int %i | %d et max_int %i | %d\n",-2147483647, -2147483647, 2147483647, 2147483647);
	printf("%i---%i\n", nbr13, nbr14);
	//TEST pour u
	printf("test pour u\n");
	int nbr22, nbr23;
	nbr22 = ft_printf("mon printf : mon nombre est le %u || %u\n", -489, 489);
	nbr23 = printf("vrai printf: mon nombre est le %u || %u\n", -489, 489);
	printf("%i---%i\n", nbr22, nbr23);
	//TEST POUR p
	printf("test pour p\n");

	//TEST pour x
	printf("test pour x\n");

	return (0);
}
