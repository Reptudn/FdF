NAME	= fdf
BUILD	= ./build/
SRC		= camera.c debug.c draw.c events.c file_utils.c main.c map.c quaternion_utils.c \
			raycast.c vector_utils.c vector_utils2.c window.c
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Werror -Wextra
COMP	= cc
INCL	=

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		$(COMP) $(FLAGS) -o $(NAME) -I $(INCL) $(SRC)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: flcean all