# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrollo <mrollo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 18:20:34 by arebelo           #+#    #+#              #
#    Updated: 2023/05/05 13:32:49 by mrollo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
# **************************************************************************** #
BINARY				= cub3D

# FILES
# **************************************************************************** #
SRCS				= main.c\
					free/clean_exit.c\
					parsing/args_check.c\
					parsing/parse.c\
					parsing/read_file.c\
					parsing/map.c\
					parsing/map_check.c\
					parsing/check_rows_cols.c\
					parsing/textures.c\
					parsing/aux.c\
					parsing/clean_color.c\
					hooks/key_letters.c\
					hooks/key_arrows.c\
					hooks/key_hooks.c\
					hooks/red_cross.c\
					rendering/images.c\
					rendering/set_vars.c\
					rendering/print_minimap.c\
					rendering/horizontal.c\
					rendering/vertical.c\
					rendering/draw_rays.c\
					rendering/draw_line.c\
					utils/colors.c\
					utils/angles.c\
					utils/join_free.c\
					gnl/get_next_line.c

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
CFLAGS				= -Wall -Wextra -g -O3
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
