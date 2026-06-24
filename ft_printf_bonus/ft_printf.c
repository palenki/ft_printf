/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:26:34 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/23 22:23:59 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(t_format info, va_list args)
{
	if (info.spec == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (info.spec == 's')
		return (ft_handle_s(info, va_arg(args, char *)));
	else if (info.spec == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (info.spec == 'd' || info.spec == 'i')
		return (ft_handle_d(info, va_arg(args, int)));
	else if (info.spec == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	else if (info.spec == 'x' || info.spec == 'X')
		return (ft_puthex(va_arg(args, unsigned int), info.spec));
	else if (info.spec == '%')
		return (ft_putchar('%'));
	return(0);
}

static void	format_identifier(const char **str, t_format *info)
{
	(*str)++;
	if (!(**str))
		return;
	if (**str == '-')
	{
		info->minus = 1;
		(*str)++;
	}
	while(**str >= '0' && **str <= '9')
	{
		info->width = info->width * 10 + **str - '0';
		(*str)++;
	}
	info->spec = **str;
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	int	count;
	va_list args;
	t_format	info;

	va_start(args, str);
	count = 0;
	while(*str)
	{
		if(*str == '%')
		{
			ft_init_format(&info);
			format_identifier(&str, &info);
			count += print_format(info, args);
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
