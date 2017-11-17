# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adeletan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 07:30:41 by adeletan          #+#    #+#              #
#    Updated: 2017/11/16 05:25:34 by adeletan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := template

LIBFT = libft/libft.a

ERROR = -Werror -Wall -Wextra

FLAGS := `SDL2-config --cflags --libs` -L./includes/SDL/ -lSDL2_image \
		-lSDL2_ttf  -L./ -lfmod
INCLUDES := -I./includes/SDL -I./includes -I./libft -I./includes/FMOD \
		-I./includes/MINISDL

SRCS := main.c	\
		MSDL_Init.c \
		MSDL_CreateWindow.c

SRCSP := $(addprefix ./srcs/,  $(SRCS))
OBJS = $(SRCS:.c=.o)
OBJSP = $(addprefix ./objs/, $(SRCS:.c=.o))
OBJS = $(SRCSP:.c=.o)

all : lib $(NAME)

lib :
	make -C libft/


$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(INCLUDES) $(ERROR)

%.o : %.c
	gcc -c -o $@ $< $(INCLUDES) $(ERROR)

clean :
	make -C libft/ clean
	rm -rf $(OBJSP) $(OBJS)

fclean : clean
	make -C libft/ fclean
	rm -rf $(NAME)

re : fclean all
