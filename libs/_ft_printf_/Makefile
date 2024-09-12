# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquissan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 14:20:56 by aquissan          #+#    #+#              #
#    Updated: 2024/05/25 14:31:08 by aquissan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SRC = ft_itoa.c ft_putstr.c ft_utils.c ft_putptr.c \
	ft_hexa.c ft_printf.c ft_putnbr.c ft_putunsign.c 
NAME =libftprintf.a
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar -rcs
RM = rm -f
BOBJ = bonus.o
BSRC = bonus.c

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@$(RM) $(BOBJ)
bonus: $(BOBJ) all
	@$(AR) $(NAME) $(BOBJ)
$(BOBJ) : $(BSRC)
	$(CC) $(CFLAGS) -c $< -o $@
fclean: clean
	@$(RM) $(NAME)
re: fclean all

.PHONY: all re clean fclean
