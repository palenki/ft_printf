/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 16:54:47 by pauhenr2          #+#    #+#             */
/*   Updated: 2026/06/23 22:13:40 by pauhenr2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int	minus;
	int	width;
	char	spec;
}	t_format;

int	ft_printf(const char *format, ...);

/* ---------FORMATATION HANDLE FUNCTIONS----------  */

int	ft_handle_d(t_format info, int nbr);
int	ft_handle_s(t_format info, char *str);

/* ---------------UTILITY FUNCTIONS---------------  */

int	ft_nbrlen(int n);
int	ft_strlen(char *str);
void	ft_init_format(t_format *info);

/* ----------------OUTPUT FUNCTIONS---------------- */

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int nbr, char specifier);

#endif
