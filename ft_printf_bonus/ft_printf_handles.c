/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:19:32 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/27 16:11:07 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	decimal_zero_padd(int nbr, int padding)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		count += ft_print_padding(padding, '0');
		count += ft_putunbr((unsigned int)-(long)nbr);
	}
	else
	{
		count += ft_print_padding(padding, '0');
		count += ft_putnbr(nbr);
	}
	return (count);
}

int	ft_handle_d(t_format info, int nbr)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	len = ft_nbrlen(nbr);
	padding = info.width - len;
	if (!info.minus)
	{
		if (info.zero)
			return (decimal_zero_padd(nbr, padding));
		count += ft_print_padding(padding, ' ');
	}
	count += ft_putnbr(nbr);
	if (info.minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}

int	ft_handle_hex(t_format info, unsigned long nbr)
{
	int	count;
	int	padding;
	int	len;

	count = 0;
	len = ft_hexlen(nbr);
	if (info.spec == 'p')
	{
		len += 2;
		if(nbr == 0)
			len = 5;
	}
	padding = info.width - len;
	if (!info.minus)
		count += ft_print_padding(padding, ' ');
	if (info.spec == 'p')
		count += ft_putptr(nbr, info.spec);
	else
		count += ft_puthex(nbr, info.spec);
	if (info.minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}

int	ft_handle_c(t_format info, char c)
{
	int	count;
	int	padding;

	count = 0;
	padding = info.width - 1;
	if (!info.minus)
		count += ft_print_padding(padding, ' ');
	count += ft_putchar(c);
	if (info.minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}

int	ft_handle_s(t_format info, char *str)
{
	int	count;
	int	len;
	int	padding;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	padding = info.width - len;
	if (!info.minus)
		count += ft_print_padding(padding, ' ');
	count += ft_putstr(str);
	if (info.minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}
