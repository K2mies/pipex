# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 09:49:02 by rhvidste          #+#    #+#              #
#    Updated: 2025/01/08 10:40:36 by rhvidste         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-------------------------------------------------------------------------------

#Variables
#-------------------------------------------------------------------------------
NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -I
RM			= rm -f
AR			= ar rcs
#------------------------------------------------------------------------------

#Colors
#------------------------------------------------------------------------------
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
#------------------------------------------------------------------------------

#Sources
#------------------------------------------------------------------------------
SRC_FILES	= 	ft_printf ft_printchar ft_print_hex ft_printnbr ft_printpercent \
				ft_printptr ft_printstr ft_printunsigned

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
#-----------------------------------------------------------------------------

#Rules
#-----------------------------------------------------------------------------
OBJF		= 	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
					@make -C $(LIBFT)
					@cp libft/libft.a .
					@mv libft.a $(NAME)
					@$(AR) $(NAME) $(OBJ)
					@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
					@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
					@mkdir -p $(OBJ_DIR)
#----------------------------------------------------------------------------

#clean
#----------------------------------------------------------------------------
clean:
					@$(RM) -rf $(OBJ_DIR)
					@make clean -C $(LIBFT)
					@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
					@$(RM) -f $(NAME)
					@$(RM) -f $(LIBFT)/libft.a
					@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
					@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
					@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"
#----------------------------------------------------------------------------

#Norminette
#----------------------------------------------------------------------------
norm:
					@norminette $(SRC) $(INCLUDE) $(LIBFT) | grep -v Norme -B1 || true
#----------------------------------------------------------------------------
.PHONY:		all clean fclean re norm
