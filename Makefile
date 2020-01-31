NAME := fillit

# directories
SRC_DIR = ./src
INC_DIR	:= ./includes
OBJ_DIR	:= ./obj
LIB_DIR	:= ./libft

# src / obj files
SRC		:= basic_calculations.c \
		   dlx_algorithm.c \
		   dlx_structures_routine.c \
		   fillit.c \
		   preparing_routine.c
OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# libraries
L_FT	:= $(LIB_DIR)/libft.a

include $(L_FT)/Makefile

# compiler and flags
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror -pedantic -std=c99
OFLAGS	:= -pipe -flto
CFLAGS	+= $(OFLAGS)

.PHONY: fclean clean all re

	all:
		mkdir -p $(OBJ_DIR)
		@$(MAKE) -C $(L_FT) --no-print-directory
		@$(MAKE) $(NAME) --no-print-directory

	$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		$(CC) $(CFLAGS) $(LIB_INC) -I $(INC_DIR) -o $@ -c $<

	$(NAME): $(OBJ)
		$(CC) $(OFLAGS) $(OBJ) $(LIB_LNK) -o $(NAME)

	clean:
		rm -rf $(OBJ_DIR)

	fclean: clean
		rm -rf $(NAME)

	re:
		@$(MAKE) fclean --no-print-directory
		@$(MAKE) all --no-print-directory

	relibs:
		@$(MAKE) -C $(L_FT) re --no-print-directory
		@$(MAKE) re --no-print-directory
