# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquissan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:19:16 by aquissan          #+#    #+#              #
#    Updated: 2024/07/23 16:37:15 by aquissan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREDITS =       "\n\n\t🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊\
		\n\t🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊\
		\n\t🎊🥳 \033[32mCongratulations!\033[0m 🥳🎊\
		\n\t🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊\
		\n\t🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊🎊\n\n"
SUCCESS = 	"\n\n\t✨✨✨✨✨✨✨✨✨✨✨✨✨\
		\n\t✨✨✨✨✨✨✨✨✨✨✨✨✨\
		\n\t✨🥳\033[32mOk!Lets start game\033[0m🥳✨\
		\n\t✨✨✨✨✨✨✨✨✨✨✨✨✨\
		\n\t✨✨✨✨✨✨✨✨✨✨✨✨✨\n\n"
MAP = maps/labirint.ber
SRC_DIR = sources
INC_DIR = includes
OBJ_DIR = objects
NAME = so_long
CC = cc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -g 
LIBXWAY = libs/mlx_linux
FT_PRINTF = libs/_ft_printf/libftprintf.a
FILES = main.c utils.c free.c split.c check_error.c check_map.c controls.c sets.c utils_2.c game.c
FT_PRINTFWAY = libs/_ft_printf
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
MAPS = A
RM = rm -f
LEAKS = --leak-check=full -s --track-origins=yes --show-leak-kinds=all

all: minilibx $(FT_PRINTF) $(NAME)
	@echo $(SUCCESS)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L$(LIBXWAY) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

minilibx: 
	make -C $(LIBXWAY)
$(FT_PRINTF):
	make -C $(FT_PRINTFWAY)

clean:
	@$(RM) $(OBJ)
	@rm -d $(OBJ_DIR)
	@make clean -C $(LIBXWAY) 
	@make clean -C $(FT_PRINTFWAY)
	@echo "All objects was removed. 😟"
fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(FT_PRINTFWAY)
	@echo "The progam was removed.😭"
push: fclean
	git add .
	git commit -m"in process"
	git push

re: fclean all

run: minilibx $(FT_PRINTF) $(NAME)
	clear
	./$(NAME) $(MAP)
	@echo $(CREDITS)
norm:
	@norminette ./$(SRC_DIR)
	@norminette ./$(INC_DIR)

leak: minilibx $(FT_PRINTF) $(NAME)
	clear
	valgrind ./$(NAME) $(MAP)
.PHONY: re clean fclean all run
