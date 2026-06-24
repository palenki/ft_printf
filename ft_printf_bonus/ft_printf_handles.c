/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handles.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 19:19:32 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/23 22:29:53 by pauhenr2         ###   ########.fr       */
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
	if (info.minus)
		count += ft_putnbr(nbr);
	while (padding > 0)
	{
		count += write(1, " ", 1);
		padding--;
	}
	if (!info.minus)
		count += ft_putnbr(nbr);
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
	if (info.minus)
		count += ft_putstr(str);
	while (padding > 0)
	{
		count += write(1, " ", 1);
		padding--;
	}
	if (!info.minus)
		count += ft_putstr(str);
	return (count);
}
