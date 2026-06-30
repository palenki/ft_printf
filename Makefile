# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauhenr2 <pauhenr2@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/16 17:34:31 by pauhenr2          #+#    #+#              #
#    Updated: 2026/06/29 23:11:40 by pauhenr2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#__________Configurations____________#

NAME = libftprintf.a
BONUS = .bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes/
SRC_DIR = srcs/
BONUS_DIR = srcs_bonus/

#___________Source Files_____________#

SRCS = $(SRC_DIR)ft_printf.c \
	$(SRC_DIR)ft_printf_text.c \
	$(SRC_DIR)ft_printf_numbers.c

BONUS_SRCS = $(BONUS_DIR)ft_printf_bonus.c \
			$(BONUS_DIR)ft_printf_text_bonus.c \
			$(BONUS_DIR)ft_printf_numbers_bonus.c \
			$(BONUS_DIR)ft_printf_handles_bonus.c \
			$(BONUS_DIR)ft_printf_length_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

#_______________Rules_______________#

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $(BONUS_OBJS)
	touch $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
