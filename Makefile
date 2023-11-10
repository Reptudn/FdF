NAME	:= FdF

CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)camera.c \
			$(SRCDIR)debug.c \
			$(SRCDIR)draw.c \
			$(SRCDIR)events.c \
			$(SRCDIR)file_utils.c \
			$(SRCDIR)main.c \
			$(SRCDIR)map.c \
			$(SRCDIR)quaternion_utils.c \
			$(SRCDIR)raycast.c \
			$(SRCDIR)vector_to_2d_conversion.c \
			$(SRCDIR)vector_utils.c \
			$(SRCDIR)vector_utils2.c

OBJS	:= ${SRCS:.c=.o}

CC		:= gcc

.PHONY: all, clean, fclean, re, libmlx

all: libmlx $(NAME)

libft:
	@make -C ./lib/libft

ft_printf:
	@make -C ./lib/ft_printf

get_next_line:
	@make -C ./lib/get_next_line

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS) libft ft_printf get_next_line
	@$(CC) $(OBJS) $(LIBS) ./lib/libft/libft.a ./lib/ft_printf/libftprintf.a ./lib/get_next_line/get_next_line.a $(HEADERS) -o $(NAME)

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/ft_printf clean
	@make -C ./lib/get_next_line clean
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@make -C ./lib/libft fclean
	@make -C ./lib/ft_printf fclean
	@make -C ./lib/get_next_line fclean
	@rm -rf $(NAME)

re: clean all
