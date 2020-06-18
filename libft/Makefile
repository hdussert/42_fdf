# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdussert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/29 07:50:24 by hdussert          #+#    #+#              #
#    Updated: 2018/05/08 10:39:23 by hdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = .
SRC_NAME = ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memccpy.c \
		   ft_memmove.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_strlen.c \
		   ft_strdup.c \
		   ft_strcpy.c \
		   ft_strncpy.c \
		   ft_strcat.c \
		   ft_strncat.c \
		   ft_strlcat.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_strnstr.c \
		   ft_strcmp.c \
		   ft_strncmp.c \
		   ft_atoi.c \
		   ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strnew.c \
		   ft_strdel.c \
		   ft_strclr.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strequ.c \
		   ft_strnequ.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strsplit.c \
		   ft_itoa.c \
		   ft_putchar.c \
		   ft_putstr.c \
		   ft_putendl.c \
		   ft_putnbr.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_pow.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_fact.c \
		   ft_strccount.c \
		   ft_strduprev.c \
		   ft_strcapitalize.c \
		   get_next_line.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = include
INC_FLAG = $(addprefix -I,$(INC_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@echo "Libft ✓"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean:
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

