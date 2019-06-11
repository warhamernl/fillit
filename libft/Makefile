# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kde-wint <kde-wint@student.codam.n>          +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/23 11:43:57 by kde-wint       #+#    #+#                 #
#    Updated: 2019/06/09 13:14:34 by kde-wint      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = atoi \
	  bzero \
	  isalnum \
	  isalpha \
	  isascii \
	  isdigit \
	  isprint \
	  itoa \
	  lstalloc \
	  lstadd \
	  lstdel \
	  lstdelone \
	  lstiter \
	  lstmap \
	  lstnew \
	  memalloc \
	  memccpy \
	  memchr \
	  memcmp \
	  memcpy \
	  memdel \
	  memmove \
	  memset \
	  putendl \
	  putendl_fd \
	  putchar \
	  putchar_fd \
	  putnbr \
	  putnbr_fd \
	  putstr \
	  putstr_fd \
	  sqrt \
	  strcap \
	  strcat \
	  strchr \
	  strclr \
	  strcmp \
	  strcpy \
	  strdel \
	  strdup \
	  strequ \
	  striter \
	  striteri \
	  strjoin \
	  strlcat \
	  strlen \
	  strmap \
	  strmapi \
	  strncat \
	  strncmp \
	  strndup \
	  strnequ \
	  strncpy \
	  strnew \
	  strnstr \
	  strrchr \
	  strreplace \
	  strrev \
	  strsplit \
	  strstr \
	  strsub \
	  strtolower \
	  strtoupper \
	  strtrim \
	  tolower \
	  toupper

SRC := $(SRC:%=ft_%.c)

OBJ := $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) -c -I./
	ar crs $(NAME) $(OBJ)

clean:
	rm -Rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all
