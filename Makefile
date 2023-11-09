NAME	= fdf
BUILD	= ./build/
SRC		= camera.c debug.c draw.c events.c file_utils.c main.c map.c quaternion_utils.c \
			raycast.c vector_utils.c vector_utils2.c window.c
OBJ		= $(SRC:.c=.o)
FLAGS	= -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit
COMP	= gcc
INCL	=

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c
		$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
		cd ./sources/miniLibX && make
		cd ../../
		$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: flcean all