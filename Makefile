# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kde-wint <kde-wint@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/20 14:52:58 by kde-wint       #+#    #+#                 #
#    Updated: 2019/05/23 13:23:55 by mlokhors      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
EXTRA =
FLAGS = -Wall -Werror -Wextra $(EXTRA)

all: $(NAME)

$(NAME):
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -c fillit_dir/*.c
	gcc $(FLAGS) *.o -L libft/ -lft
#this needs to compile to executable "fillit" before submission

clean:
	rm -f *.o
	rm a.out

fclean: clean
	make -C libft/ fclean
#this needs to changed to the standard functioning before submission

re: clean all

lldb:
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -g fillit_dir/*.c -L libft/ -lft

lldbclean:
	rm a.out
	rm -Rf a.out.dSYM

lldbfclean:
	make -C libft/ fclean
	rm a.out
	rm -Rf a.out.dSYM

lldbre: lldbclean lldb
