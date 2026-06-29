/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:54:47 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/28 20:59:27 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		zero;
	int		minus;
	int		width;
	int		precision;
	char	spec;
}	t_format;

int		ft_printf(const char *format, ...);

/* ---------FORMATATION HANDLE FUNCTIONS----------  */

int		ft_handle_d(t_format info, int nbr);
int		ft_handle_u(t_format into, unsigned int nbr);
int		ft_handle_s(t_format info, char *str);
int		ft_handle_c(t_format info, char c);
int		ft_handle_hex(t_format info, unsigned long nbr);
int		ft_handle_p(t_format info, void *ptr);

/* ---------------UTILITY FUNCTIONS---------------  */

int		ft_nbrlen(int n);
int		ft_strlen(char *str);
int		ft_hexlen(unsigned long nbr);
int		ft_unbrlen(unsigned int nbr);
void	ft_init_format(t_format *info);

/* ----------------OUTPUT FUNCTIONS---------------- */

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putptr(unsigned long nbr, char specifier);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_puthex(unsigned long nbr, char specifier);
int		ft_print_padding(int padding, char c);
int		ft_decimal_zero_padd(long nbr, int padding);

#endif
