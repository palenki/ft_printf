/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:26:34 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/20 21:58:54 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, void *));
	return(count);
}

static int	ft_parse_type(const char **format, va_list args)
{
	char specifier;

	(*format)++;
	if (!(**format))
		return (0);
	specifier = **format;
	(*format)++;
	return(ft_dispatch(specifier, args));
}

int	ft_printf(const char *format, ...)
{
	int	count;
	va_list args;

	va_start(args, format);
	count = 0;
	while(*format)
	{
		if(*format == '%')
			count += ft_parse_type(&format, args);
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
