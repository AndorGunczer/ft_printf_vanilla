# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 14:00:18 by agunczer          #+#    #+#              #
#    Updated: 2021/07/09 08:47:47 by agunczer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_puthexlower_fd.c ft_puthexupper_fd.c ft_puthexpointer_fd.c ft_putunsnbr_fd.c \
		ft_handletype.c ft_printf.c ./libft/ft_putnbr_fd.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c \
		ft_widthcounter.c ft_detertype.c ft_itoa_long.c ./libft/ft_strdup.c ./libft/ft_strlcpy.c \
		./libft/ft_strlen.c ./libft/ft_calloc.c
NAME = libftprintf.a

all: ${NAME}
	
${NAME}: ${SRC}
	gcc -c $^
	ar -rc libftprintf.a *.o

clean:
	rm -f *.o

fclean: clean
	rm -f ${NAME}

re: fclean all