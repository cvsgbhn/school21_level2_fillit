NAME = fillit

SRC = fillit.c main.c

HEADER = fillit.h libft.h

LIBS = libft.a -lsal

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	clang -Wall -Wextra -Werror -I libft/ -o fillit.o -c fillit.c
	clang -Wall -Wextra -Werror -I libft/ -o main.o -c main.c
	clang -o test_fillit main.o fillit.o -I libft/includes -L libft/ -lft

clean:
	/bin/rm -rf $(OBJECTS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: fclean clean all re