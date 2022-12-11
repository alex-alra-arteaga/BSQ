##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that creates library
##

SRC 	=   $(wildcard *.c) \
            $(wildcard ./lib/my/src/conv/*.c) \
            $(wildcard ./lib/my/src/flags/*.c) \
            $(wildcard ./lib/my/src/precision/*.c) \
            $(wildcard ./lib/my/src/width/*.c) \
            $(wildcard ./lib/my/utils/*.c) \
            $(wildcard ./lib/my/*.c)


NAME	=	libmy.a

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -g3 -I./my/utils

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
