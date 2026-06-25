/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 18:38:31 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/24 18:53:06 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void     ft_init_format(t_format *info)
{
        info->minus = 0;
        info->width = 0;
        info->spec = 0;
}

int	ft_nbrlen(int n)
{
	int	len;
	long	nbr;

	nbr = n;
	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_hexlen(unsigned long nbr)
{
	int	len;

	len = 1;
	while (nbr >= 16)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}
