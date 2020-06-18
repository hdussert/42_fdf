# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdussert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/29 07:50:24 by hdussert          #+#    #+#              #
#    Updated: 2018/08/16 00:33:24 by hdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FDF

SRC_PATH = src
SRC_NAME = main.c \
		   init.c \
		   draw.c \
		   map.c \
		   vectors.c \
		   rotation.c \
		   events.c \
		   color.c \
		   map_r.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = include minilibx_macos
INC_FLAG = $(addprefix -I,$(INC_PATH))

LDFLAGS = -Llibft
LDLIBS = -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LBXFLAGS = -Lminilibx_macos -lmlx
FWFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $(NAME) $(FWFLAGS) $(LBXFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

fast: $(eval CFLAGS := -Wall -Wextra -Werror -O3) all

refast: $(eval CFLAGS := -Wall -Wextra -Werror -O3) re

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

