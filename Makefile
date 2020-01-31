.PHONY: clean fclean re make all

FILENAMES = fillit.c
FILENAMES +=  basic_calculations.c
FILENAMES += dlx_algorithm.c dlx_structures_routine.c
FILENAMES += preparing_routine.c
NAME = fillit

SRCS	=$(addprefix srcs/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./Libft/ -lft

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: srcs/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./Libft
	@make clean -C ./Libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./Libft
	@rm -f $(NAME)

build:
	@mkdir build/
