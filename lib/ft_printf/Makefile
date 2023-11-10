CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ./utils/conversion.c ./utils/base_system_conversion.c ./utils/helper.c ./utils/itoa.c ./utils/ltoa.c ./utils/put_hex.c
OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

.PHONY: all clean clean re

all: $(NAME)

$(NAME): $(OBJS)
		ar -rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS)

fclean: clean
		rm -f $(NAME)
	
re: fclean all