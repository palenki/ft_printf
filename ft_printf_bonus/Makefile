# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 17:34:31 by pauhenr2          #+#    #+#              #
#    Updated: 2026/06/23 20:11:45 by pauhenr2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#__________Configurations____________#

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

#___________Source Files_____________#

SRCS = ft_printf.c \
	ft_printf_text.c \
	ft_printf_numbers.c \
	ft_printf_length.c \
	ft_printf_handles.c

OBJS = $(SRCS:.c=.o)

#_______________Rules_______________#

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
