# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kde-wint <kde-wint@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/20 14:52:58 by kde-wint      #+#    #+#                  #
#    Updated: 2019/05/20 14:52:59 by kde-wint      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fillit
EXTRA =
FLAGS = -Wall -Werror -Wextra $(EXTRA)

all: $(NAME)

$(NAME):
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -c fillit_dir/*.c
	gcc $(FLAGS) -o $(NAME) *.o -L libft/ -lft

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)
	rm -Rf $(NAME).dSYM
	make -C libft/ fclean

re: fclean all

lldb: fclean
	make -C libft/ && make -C libft/ clean
	gcc $(FLAGS) -c fillit_dir/*.c
	gcc $(FLAGS) -g -o $(NAME) *.o -L libft/ -lft