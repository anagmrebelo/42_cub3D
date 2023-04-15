# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anarebelo <anarebelo@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 18:20:34 by arebelo           #+#    #+#              #
#    Updated: 2023/04/15 15:02:58 by anarebelo        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
BINARY				= cub3D

# FILES
# **************************************************************************** #
SRCS				= main.c\
					parsing/args_check.c\
					free/clean_exit.c

MK					= Makefile

OBJS				=${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}
DEPS				=${addprefix ${OBJS_DIR}, ${SRCS:.c=.d}}


# DIRECTORY
# **************************************************************************** #
OBJS_DIR			= objs/
SRCS_DIR			= srcs/
INC_DIR				= inc/
LIBFT_DIR			= libft
MINILIBX_DIR		= mlx

# COMPILATION
# **************************************************************************** #
LINK				= gcc
CC					= gcc -c
DEPFLAGS			= -MMD -MP
CFLAGS				= -Wall -Wextra
RM					= rm -rf

# LIBRARIES
# **************************************************************************** #
INCLUDE				= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MINILIBX_DIR)
LIBS_EXEC			= $(LIBFT_DIR)/libft.a
LIBS_EXEC			+= $(MINILIBX_DIR)/libmlx.a
LIBS				= -L./mlx/ -lmlx -framework OpenGL -framework AppKit -L./libft/ -lft

# RULES
# **************************************************************************** #
all:	make_libft make_minilibx $(BINARY)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c $(MK)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDE) $< -o $@

make_libft:
					@make -C $(LIBFT_DIR)

make_minilibx:
					@make -C $(MINILIBX_DIR)

$(BINARY): $(OBJS) $(LIBS_EXEC)
					$(LINK) $(CFLAGS) $(LIBS) -o $@ $^ 

clean:
					@$(RM) $(OBJS_DIR)
					@make clean -s -C $(LIBFT_DIR)
					@make clean -s -C $(MINILIBX_DIR)

fclean: clean
					@$(RM) $(BINARY)
					@make fclean -s -C $(LIBFT_DIR)

re: fclean all

-include ${DEPS}

.PHONY: all bonus clean fclean re
