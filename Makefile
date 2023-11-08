NAME	= fdf
SRC		= main.c camera.c draw.c file_utils.c map.c vector_utils.c window.c quaternion_utils.c
FLAGS	= -Wall -Werror -Wextra
INCL	=

all:
	cc $(FLAGS) -o -I $(INCL) $(NAME) $(SRC)

clean:

fclean: clean

re: