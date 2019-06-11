# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kde-wint <kde-wint@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/20 14:52:58 by kde-wint       #+#    #+#                 #
#    Updated: 2019/05/27 20:56:40 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
EXTRA =
FLAGS = -Wall -Werror -Wextra $(EXTRA)

all: $(NAME)

$(NAME):
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -I./ -c fillit_dir/*.c
	gcc $(FLAGS) -o $(NAME) *.o -I./  -L libft/ -lft

clean:
	rm -f *.o

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: clean
	rm -f $(NAME)
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -I./ -c fillit_dir/*.c
	gcc $(FLAGS) -o $(NAME) *.o -I./  -L libft/ -lft

lldb:
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -g -o $(NAME) fillit_dir/*.c -I./ -L libft/ -lft

lldbclean: clean

lldbfclean: fclean
	rm -Rf $(NAME).dSYM

lldbre: clean
	rm -f $(NAME)
	rm -Rf $(NAME).dSYM
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -g -o $(NAME) fillit_dir/*.c -I./ -L libft/ -lft

# INSERT THIS VERSION BEFORE SUBMITTING
#
#NAME = fillit
#EXTRA =
#FLAGS = -Wall -Werror -Wextra $(EXTRA)
#
#all: $(NAME)
#
#$(NAME):
#	make -C libft/ re
#	gcc $(FLAGS) -I./ -c fillit_dir/*.c
#	gcc $(FLAGS) -o $(NAME) *.o -I./  -L libft/ -lft
#
#clean:
#	rm -f *.o
#	make -C libft/ clean
#
#fclean:
#	rm -f *.o
#	make -C libft/ fclean
#	rm -f $(NAME)
#
#re: fclean all
#
#lldb:
#	make -C libft/ fclean && make -C libft/
#	gcc $(FLAGS) -g -o $(NAME) fillit_dir/*.c -I./ -L libft/ -lft
#
#lldbclean: clean
#
#lldbfclean: fclean
#	rm -Rf $(NAME).dSYM
#
#lldbre: lldbfclean lldb