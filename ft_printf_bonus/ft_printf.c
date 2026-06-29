/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 11:26:34 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/28 21:07:37 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(t_format info, va_list args)
{
	if (info.spec == 'c')
		return (ft_handle_c(info, va_arg(args, int)));
	else if (info.spec == 's')
		return (ft_handle_s(info, va_arg(args, char *)));
	else if (info.spec == 'p')
		return (ft_handle_p(info, va_arg(args, void *)));
	else if (info.spec == 'd' || info.spec == 'i')
		return (ft_handle_d(info, va_arg(args, int)));
	else if (info.spec == 'u')
		return (ft_handle_u(info, va_arg(args, unsigned int)));
	else if (info.spec == 'x' || info.spec == 'X')
		return (ft_handle_hex(info, va_arg(args, unsigned int)));
	else if (info.spec == '%')
		return (ft_handle_c(info, '%'));
	return (0);
}

static void	parse_flags(const char **str, t_format *info)
{
	while (**str == '-' || **str == '0')
	{
		if (**str == '-')
			info->minus = 1;
		else if (**str == '0')
			info->zero = 1;
		(*str)++;
    }

}

static void	format_identifier(const char **str, t_format *info)
{
	(*str)++;
	if (!(**str))
		return ;
	parse_flags(str, info);
	while (**str >= '0' && **str <= '9')
	{
		info->width = info->width * 10 + **str - '0';
		(*str)++;
	}
	if (**str == '.')
	{
		info->zero = 0;
		(*str)++;
		info->precision = 0;
		 while (**str >= '0' && **str <= '9')
		{
			info->precision = info->precision * 10 + (**str - '0');
			(*str)++;
		}
	}
	info->spec = **str;
	(*str)++;
}

int	ft_printf(const char *str, ...)
{
	int			count;
	va_list		args;
	t_format	info;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
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
