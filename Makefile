##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## funcion which
##

NAME	=	my_sokoban

LIB	=	-L lib/my/ -lmy

INCLUDE	=	-I ./include/

SRC	= 	src/main.c	\
		src/create_map.c	\
		src/down.c	\
		src/up.c	\
		src/filas_col.c	\
		src/key.c	\
		src/left.c	\
		src/my_sokoban.c	\
		src/pos_xo.c	\
		src/right.c	\
		src/valid.c	\
		src/keydch.c	\

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): 	$(OBJ)
		make -C ./lib/my
		gcc -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB) -lncurses

clean:
	rm -f $(NAME)

fclean: clean
	rm -f libmy.a
	rm -f lib/my/libmy.a
	rm -f ./lib/my/*.o
	rm -f ./src/*.o

re: fclean all

library: fclean
	make -C lib/my/ re

exec:	re
	./$(NAME)
