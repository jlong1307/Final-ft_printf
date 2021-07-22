/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlong <jlong@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 10:09:11 by jlong             #+#    #+#             */
/*   Updated: 2021/07/22 15:33:30 by jlong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFH_H
# define PRINTFH_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <wchar.h>

typedef struct s_flags
{
	int			size;
}				t_format;

int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
size_t			ft_putnstr(const char *str, size_t len);
void			ft_conver_x(unsigned long nbr, t_format *format_len);
void			print_int(va_list ap, t_format *format_len);
void			print_int(va_list ap, t_format *format_len);
void			print_char(va_list ap, t_format *format_lenn);
void			print_str(va_list ap, t_format *format_len);
void			ft_putchar(char c, t_format *format_len);
void			ft_putnbr(long long nb, t_format *format_len);
void			ft_check_conv(va_list ap, const char *str,
					t_format *format_len);
void			ft_putchar(char c, t_format *format_len);
void			ft_putnbr(long long nb, t_format *format_len);
void			printf_u(va_list ap, t_format *format_len);
void			printf_pointer(va_list ap, t_format *format_len);
void			printf_x(va_list ap, t_format *format_len);
int				ft_readerprintf(va_list ap, const char *format,
					t_format *format_len);
void			ft_putchar(char c, t_format *format_len);
void			ft_putnbr(long long nb, t_format *format_len);

#endif
