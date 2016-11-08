# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/11/08 17:28:32 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE =		rtv1
INCLUDES =	libft/libft.a
HEADER =	rt_v1.h
MKINC =		make -C libft/
MLX =		-lmlx -framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES =	main.c parser.c add_obj.c event.c tools.c
OBJS =		$(SOURCES:.c=.o)

all :		$(EXE)
$(EXE) :	$(OBJS) $(HEADER) Makefile
			$(MKINC)
			$(CC) $(CFLAGS) -c $(SOURCES)
			$(CC) $(CFLAGS) -o $(EXE) $(OBJS) -lm $(INCLUDES) $(MLX)
norm :
			norminette $(SOURCES) $(HEADER)
meteo :
			curl http://wttr.in/Paris
clean :
			-rm -f $(OBJS)
fclean :	clean
			$(MKINC) fclean
			-rm -f $(EXE)
re :		fclean all
