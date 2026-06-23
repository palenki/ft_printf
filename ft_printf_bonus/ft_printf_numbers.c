/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:12:53 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/20 23:45:34 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_hex(unsigned long long address)
{
	int	count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (address >= 16)
		count += ft_putptr_hex(address / 16);
	count += ft_putchar(base[address % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write (1, "0x", 2);
	count += ft_putptr_hex((unsigned long long)ptr);
	return (count);
}

int	ft_puthex(unsigned int nbr, char specifier)
{
	int	count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (specifier == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_puthex(nbr / 16, specifier);
	count += ft_putchar(base[nbr % 16]);
	return (count);
}

int	ft_putnbr(int	n)
{
	long	nbr;
	int	count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar((nbr % 10) + '0');
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	unsigned int	div;
	unsigned int	temp;
	char		digit;
	int 		count;

	count = 0;
	div = 1;
	temp = n;
	while (temp >= 10)
	{
		div *= 10;
		temp /= 10;
	}
	while (div > 0)
	{
		digit = (n / div) + '0';
		count += ft_putchar(digit);
		n = n % div;
		div /= 10;
	}
	return (count);
}
