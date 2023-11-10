# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkauker <jkauker@student.42heilbrnn.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 12:22:34 by jonask            #+#    #+#              #
#    Updated: 2023/10/17 13:30:39 by jkauker          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS 	= -Wall -Werror -Wextra -I ./
CFILES 	= ft_bzero.c ft_itoa.c ft_strrchr.c ft_atoi.c ft_calloc.c ft_isascii.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_memset.c ft_memchr.c ft_putstr_fd.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strncmp.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_isspace.c
BONUS 	= ft_lstadd_back_bonus.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstsize_bonus.c
EXTRA	= ft_isspace.c
OBJ 	= $(CFILES:.c=.o)
BONOBJ  = $(BONUS:.c=.o)
CC		= cc

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

bonus: $(BONOBJ)
		ar -rcs $(NAME) $(BONOBJ)

clean:
		rm -rf $(OBJ) $(BONOBJ)

fclean: clean
		rm -f $(NAME)

re:
		fclean all