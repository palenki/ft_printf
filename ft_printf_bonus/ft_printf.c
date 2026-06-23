/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:26:34 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/23 00:04:35 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_puthex(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return(0);
}

static void	init_format(t_format *info)
{
	info->spec = 0;
}

static void	format_identifier(const char **str, t_format *info)
{
	(*str)++;
	if (!(**str))
		return;
	info->spec = **str;
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list args;
	t_format	info;

	init_format(&info);
	va_start(args, str);
	count = 0;
	while(*str)
	{
		if(*str == '%')
		{
			format_identifier(&str, &info);
			count += print_format(info.spec, args);
		}
		else
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (count);
}
