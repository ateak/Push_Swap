# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ateak <ateak@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:09:22 by ateak             #+#    #+#              #
#    Updated: 2022/09/30 16:07:42 by ateak            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
NAME_BONUS	=	checker

MAIN_DIR	=	main
BONUS_DIR	=   	bonus

SRC_F		=	push_swap.c\
			creating_node.c\
			creating_stacks.c\
			glb_init_and_parsing.c\
			help_functions.c\
			instructions_part1.c\
			instructions_part2.c\
			need_for_pushing_functions_part1.c\
			need_for_pushing_functions_part2.c\
			need_for_pushing_functions_part3.c\
			need_for_pushing_functions_part4.c\

MAIN       	= 	$(addprefix $(MAIN_DIR)/, $(SRC_F))

SRC_BONUS_F	=	checker_bonus.c\
			comparing_instructions_bonus.c\
			creating_stack_a_bonus.c\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			glb_init_and_parsing_bonus.c\
			help_functions_bonus.c\
			instructions_part1_bonus.c\
			instructions_part2_bonus.c\

BONUS 		= 	$(addprefix $(BONUS_DIR)/, $(SRC_BONUS_F))	

SRC 		= 	$(MAIN)
SRC_BONUS 	= 	$(BONUS)

HEADER 		= 	main/push_swap.h	
HEADER_BONUS 	= 	bonus/checker_bonus.h	

OBJ		=	$(SRC:%.c=%.o)
OBJ_BONUS 	= 	$(SRC_BONUS:%.c=%.o)

FLAGS		=	-Wall -Wextra -Werror -I$(HEADER)
FLAGS_BONUS	=	-Wall -Wextra -Werror -I$(HEADER_BONUS)

.PHONY	:	all clean fclean re

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	$(CC) ${OBJ} -o ${NAME}

%.o : %.c $(if $(findstring bonus, $(MAKECMDGOALS)), $(HEADER_BONUS), $(HEADER))

bonus	: $(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) ${OBJ_BONUS} -o ${NAME_BONUS}


clean	:
	@rm -f $(OBJ)	$(OBJ_BONUS)

fclean	: 	clean
	@rm -f $(NAME)	$(NAME_BONUS)

re	:	fclean all
