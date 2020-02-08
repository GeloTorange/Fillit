# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 17:52:48 by torange           #+#    #+#              #
#    Updated: 2019/12/26 20:57:00 by rmaple           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

INC_DIR		= ./includes
SRC_DIR		= ./src
OBJ_DIR		= ./obj

HEADERS		= fillit.h
SOURCES		= \
				check.c \
				check_pos.c \
				init_ter.c \
				input_ter.c \
				main.c \
				lstdel.c \
				map.c \
				other.c \
				print.c


LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= gcc
WFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I$(INC_DIR)/ -I$(LIBFT_DIR)/

INCS		= $(addprefix $(INC_DIR)/, $(HEADERS))
SRCS		= $(addprefix $(SRC_DIR)/, $(SOURCES))
OBJS		= $(addprefix $(OBJ_DIR)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(WFLAGS) $(IFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) Makefile
	@mkdir -p ${@D}
	$(CC) $(WFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ_DIR)
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette $(INCS) $(SRCS)

.PHONY: all clean fclean re norm $(LIBFT)


