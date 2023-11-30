# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avoronko <avoronko@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 16:00:43 by avoronko          #+#    #+#              #
#    Updated: 2023/09/25 18:15:50 by avoronko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		:= 	clang
FLAGS 	:= 	-Wall -Wextra -Werror
RM		:=	rm -f

NAME	:=	libft.a

SRCS	:= 	ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c  \
			ft_atoi.c ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c 	 \
			ft_atoli.c ft_is_sign.c ft_is_space.c							 \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c 	 \
			ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c 	 \
			ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c 	 \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	 \
			ft_convert_base.c ft_uitoa.c ft_lstnew.c ft_lstadd_front.c		 \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c 		 \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	:=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME) $(OBJS)

re:			fclean all

.PHONY: 	all clean fclean re 
