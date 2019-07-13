# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kde-wint <kde-wint@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/20 14:52:58 by kde-wint       #+#    #+#                 #
#    Updated: 2019/07/06 12:34:33 by kde-wint      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
EXTRA =
FLAGS = -Wall -Werror -Wextra $(EXTRA)

CC=gcc

SRC_DIR=./fillit_dir
OBJ_DIR=./.obj

OBJ_NAMES=	\
			main \
			main_auxiliary \
			reader \
			shifting \
			totalread \
			zeewier_auxiliary \
			zeewier \

OBJS = $(patsubst %, $(OBJ_DIR)/%.o, $(OBJ_NAMES))
SRCS = $(patsubst %, $(SRC_DIR)/%.c, $(OBJ_NAMES))

LIBFT_DIR=./libft
LIBFT_A=$(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L./$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) -c -o $@ $< $(FLAGS) -I./$(SRC_DIR) -I./$(LIBFT_DIR)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:
	$(MAKE) -j10 _re

_re: 
	$(MAKE) fclean
	$(MAKE) all

lldb: 
	$(MAKE) EXTRA=-g $(NAME)
	lldb fillit test

lldbre: 
	$(MAKE) -j10 _lldbre

_lldbre:
	$(MAKE) fclean
	$(MAKE) lldb
