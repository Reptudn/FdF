NAME	:= fdf

CFLAGS	:= -Wextra -Wall -Werror

LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include

LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCDIR := ./src/

SRCS	:=  $(SRCDIR)camera.c \
			$(SRCDIR)main.c \
			$(SRCDIR)map.c \
			$(SRCDIR)debug.c \
			$(SRCDIR)window/draw.c \
			$(SRCDIR)window/window_ui.c \
			$(SRCDIR)events/event_key.c \
			$(SRCDIR)events/event_mouse.c \
			$(SRCDIR)events/event_window.c \
			$(SRCDIR)utils/quaternion_utils.c \
			$(SRCDIR)utils/file_utils.c \
			$(SRCDIR)utils/vector_utils.c \
			$(SRCDIR)utils/vector_utils2.c \
			$(SRCDIR)utils/color_utils.c \
			$(SRCDIR)utils/hex_to_color.c \
			$(SRCDIR)utils/center_points.c \
			$(SRCDIR)utils/ft_realloc.c \
			$(SRCDIR)conversion/perspective_projection.c \
			$(SRCDIR)conversion/isometric.c \

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
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<) \n"

$(NAME): $(OBJS) libft ft_printf get_next_line
	@$(CC) $(OBJS) $(LIBS) ./lib/libft/libft.a ./lib/ft_printf/libftprintf.a ./lib/get_next_line/get_next_line.a $(HEADERS) -o $(NAME) && printf "Compilation finished!\n"

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

re: fclean all
