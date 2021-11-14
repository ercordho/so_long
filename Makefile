# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ercordho <ercordho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/09 11:21:20 by ercordho          #+#    #+#              #
#    Updated: 2021/11/14 02:30:33 by ercordho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
RM				=	rm -f

OS := $(shell uname -s)
ifeq ($(OS),Darwin)
	MLX			=	minilibx-mac
	COMPILE		=	-L $(MLX) -lmlx -framework OpenGL -framework AppKit -lz
endif
ifeq ($(OS),Linux)
	MLX			=	minilibx-linux
	COMPILE		=	-lXext -lX11 -lm
endif

SRCS			=	so_long_core/srcs/ascii/ft_isalnum.c \
					so_long_core/srcs/ascii/ft_isalpha.c \
					so_long_core/srcs/ascii/ft_ischarset.c \
					so_long_core/srcs/ascii/ft_isdigit.c \
					so_long_core/srcs/dot/dot_add.c \
					so_long_core/srcs/draw/draw_map.c \
					so_long_core/srcs/error/error_bad_ext.c \
					so_long_core/srcs/error/error_extract_file_content.c \
					so_long_core/srcs/error/error_fee_many_arg.c \
					so_long_core/srcs/error/error_file_not_found.c \
					so_long_core/srcs/error/error_map_is_empty.c \
					so_long_core/srcs/error/error_map_is_too_small.c \
					so_long_core/srcs/error/error_map_isnt_rectangular.c \
					so_long_core/srcs/error/error_no_ext.c \
					so_long_core/srcs/error/error_parse_map_count_of_exit.c \
					so_long_core/srcs/error/error_parse_map_count_of_item.c \
					so_long_core/srcs/error/error_parse_map_count_of_player.c \
					so_long_core/srcs/error/error_parse_map_len.c \
					so_long_core/srcs/error/error_parse_map_min_len.c \
					so_long_core/srcs/error/error_parse_map_side.c \
					so_long_core/srcs/error/error_parse_map_uppper_lower.c \
					so_long_core/srcs/error/error_sprites_not_found.c \
					so_long_core/srcs/error/error_too_much_movement.c \
					so_long_core/srcs/events/close_windows.c \
					so_long_core/srcs/events/eventhandler.c \
					so_long_core/srcs/events/get_key_down.c \
					so_long_core/srcs/events/move_player.c \
					so_long_core/srcs/file/file_get_content.c \
					so_long_core/srcs/file/file_get_data.c \
					so_long_core/srcs/file/file_get_ext.c \
					so_long_core/srcs/file/file_init_data.c \
					so_long_core/srcs/init/init_map.c \
					so_long_core/srcs/init/init_mlx.c \
					so_long_core/srcs/init/init_move.c \
					so_long_core/srcs/init/init_sprites.c \
					so_long_core/srcs/memory/ft_memcpy.c \
					so_long_core/srcs/memory/ft_memdel.c \
					so_long_core/srcs/memory/ft_memdels.c \
					so_long_core/srcs/memory/ft_memset.c \
					so_long_core/srcs/memory/ft_memsetmal.c \
					so_long_core/srcs/memory/ft_realloc.c \
					so_long_core/srcs/parse/parse_file.c \
					so_long_core/srcs/parse/parse_map.c \
					so_long_core/srcs/read/get_next_line.c \
					so_long_core/srcs/string/count_number_recurrence_groups.c \
					so_long_core/srcs/string/ft_split.c \
					so_long_core/srcs/string/ft_strcat.c \
					so_long_core/srcs/string/ft_strcmp.c \
					so_long_core/srcs/string/ft_strdup.c \
					so_long_core/srcs/string/ft_strlen.c \
					so_long_core/srcs/string/ft_strncmp.c \
					so_long_core/srcs/string/ft_strslen.c \
					so_long_core/srcs/success/success_extract_file_content.c \
					so_long_core/srcs/success/success_file_found.c \
					so_long_core/srcs/success/success_game_is_finish.c \
					so_long_core/srcs/success/success_map_check.c \
					so_long_core/srcs/success/success_sprites_found.c \
					so_long_core/srcs/write/ft_putchar.c \
					so_long_core/srcs/write/ft_putendl.c \
					so_long_core/srcs/write/ft_putendls.c \
					so_long_core/srcs/write/ft_putnbr.c \
					so_long_core/srcs/write/ft_putstr.c \
					so_long_core/srcs/write/ft_putstrs.c \
					so_long_core/srcs/so_long.c \
					so_long_core/main.c
OBJS			=	$(SRCS:.c=.o)

all				:	$(NAME)
bonus			:	$(NAME_BONUS)
$(NAME) 		: 	$(OBJS)
					@make -C $(MLX)
					@$(CC) -o $@ $^ $(MLX)/libmlx.a $(COMPILE) $(CFLAGS)
%.o				:	%.c %.h
					@$(CC) -w $(CFLAGS) -c $< $(MLX)/libmlx.a
clean			:
					@$(RM) $(OBJS)
fclean			:	clean
					@$(RM) $(NAME)
re				:	fclean all
.PHONY			:	all clean fclean re so_long
