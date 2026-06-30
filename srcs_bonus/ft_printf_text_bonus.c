/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 13:45:06 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/29 22:14:00 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
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

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

int	ft_print_padding(int padding, char c)
{
	int	count;

	count = 0;
	while (padding > 0)
	{
		count += write(1, &c, 1);
		padding--;
	}
	return (count);
}

int	ft_decimal_zero_padd(long nbr, int padding)
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
		count += ft_putunbr((unsigned int)nbr);
	}
	return (count);
}
