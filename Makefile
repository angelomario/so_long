# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aquissan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/23 16:19:16 by aquissan          #+#    #+#              #
#    Updated: 2024/08/27 15:39:56 by aquissan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREDITS =       "\033[32mCongratulations!\033[0m"
SUCCESS = 	"\033[32mOk! Lets start game\033[0m"
MAP = maps/any.ber
CC = cc
CFLAGS = -I$(INC_DIR) -Wall -Wextra -Werror -g 
LIBXWAY = libs/mlx_linux
INC_DIR = includes
FT_PRINTF = libs/_ft_printf_/libftprintf.a
FT_PRINTFWAY = libs/_ft_printf_
RM = rm -f
LEAKS = --leak-check=full -s --track-origins=yes --show-leak-kinds=all

#MANDATORY PART
SRC_DIR = sources
OBJ_DIR = objects
NAME = so_long
FILES = main.c utils.c free.c split.c check_error.c\
		check_map.c controls.c sets.c utils_2.c game.c\
		strlen.c
SRC = $(addprefix $(SRC_DIR)/, $(FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

#BONUS PART
NAME_BONUS = so_long_bonus
SRC_DIR_BONUS = sources_bonus
OBJ_DIR_BONUS = objects_bonus
FILES_BONUS = check_error_bonus.c free_bonus.c sets_bonus.c utils_bonus.c\
				check_map_bonus.c game_bonus.c split_bonus.c set_run.c\
				controls_bonus.c main_bonus.c utils_2_bonus.c set_standing.c\
				set_atack.c set_world.c set_up.c delete_image.c set_extra.c\
				ft_itoa.c animations_bonus.c direction_bonus.c enemy_controls_bonus.c\
				animation_enemies_bonus.c ia_enemy_bonus.c initialize_enemies_bonus.c\
				finish_bonus.c reach_bonus.c extras_bonus.c get_box.c strlen_bonus.c
SRC_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS))
OBJ_BONUS = $(addprefix $(OBJ_DIR_BONUS)/, $(FILES_BONUS:.c=.o))

# SHELL := /bin/bash

all: minilibx $(FT_PRINTF) $(NAME)
	@echo $(SUCCESS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L$(LIBXWAY) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

minilibx: 
	make -C $(LIBXWAY)
$(FT_PRINTF):
	make -C $(FT_PRINTFWAY)

#BONUS RULES
bonus: minilibx $(FT_PRINTF) $(NAME_BONUS)
	@echo $(SUCCESS)

$(NAME_BONUS): $(OBJ_BONUS) 
	$(CC) $(OBJ_BONUS) $(FT_PRINTF) -Lmlx_linux -lmlx_Linux -L$(LIBXWAY) -Imlx_linux -lX11 -lXext -lm -lz -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@	$(CC) -c $< -o $@

clean:
	@make clean -C $(LIBXWAY) 
	@make clean -C $(FT_PRINTFWAY)
	@$(RM) $(OBJ)
	@$(RM) $(OBJ_BONUS)
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	clear
	@echo "All objects was removed."
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@make fclean -C $(FT_PRINTFWAY)
	clear
	@echo "The progam was removed."
push: fclean
	git add .
	git commit -m"in process"
	git push

re: fclean all

run: minilibx $(FT_PRINTF) $(NAME)
	clear
	./$(NAME) $(MAP)
run_bonus: minilibx $(FT_PRINTF) $(NAME_BONUS)
# 	clear
	./$(NAME_BONUS) $(MAP)
norm:
	@norminette ./$(SRC_DIR)
	@norminette ./$(SRC_BONUS)
	@norminette ./$(INC_DIR)

leak: minilibx $(FT_PRINTF) $(NAME)
	clear
	valgrind ./$(NAME) $(MAP)
leak_bonus: minilibx $(FT_PRINTF) $(NAME_BONUS)
	clear
	valgrind --leak-check=full -s --track-origins=yes ./$(NAME_BONUS) $(MAP)
.PHONY: re clean fclean all run
