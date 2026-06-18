/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:26:34 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/18 17:01:30 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handleflag(const char **format, va_list args)
{
	int	sub_count;

	sub_count = 0;
	(*format)++;
	if (**format == 'c')
		sub_count = ft_putchar(va_arg(args, int));
	(*format)++;
	return(sub_count);
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
			count += ft_handleflag(&format, args);
		else
		{
			count += ft_putchar(*format);
			format++;
		}
	}
	va_end(args);
	return (count);
}
