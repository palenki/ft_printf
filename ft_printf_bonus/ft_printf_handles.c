/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:19:32 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/28 20:07:46 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
			return (ft_decimal_zero_padd(nbr, padding));
		count += ft_print_padding(padding, ' ');
	}
	count += ft_putnbr(nbr);
	if (info.minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}

int ft_handle_u(t_format info, unsigned int nbr)
{
    int	count;
    int	len;
    int	padding;

    count = 0;
    len = ft_unbrlen(nbr);
    padding = info.width - len;
    if (!info.minus)
    {
        if (info.zero)
            return (ft_decimal_zero_padd(nbr, padding));
        count += ft_print_padding(padding, ' ');
    }
    count += ft_putunbr(nbr);
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
	padding = info.width - len;
	if (!info.minus)
	{
		if(info.zero)
			count += ft_print_padding(padding, '0');
		else
			count += ft_print_padding(padding, ' ');
	}
	count += ft_puthex(nbr, info.spec);
	if (info.minus)
		count += ft_print_padding(padding, ' ');
	return (count);
}

int ft_handle_p(t_format info, void *ptr)
{
    int count;
    int padding;
    int len;

    count = 0;
    len = ft_hexlen((unsigned long)ptr) + 2;
	if (!ptr)
		len = 5;
    padding = info.width - len;
    if (!info.minus)
        count += ft_print_padding(padding, ' ');
    count += ft_putptr((unsigned long)ptr, info.spec);
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
