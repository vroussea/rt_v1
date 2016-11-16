# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/11/16 10:54:53 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE1 =		rtv1
EXE2 =		scmk
INCLUDES =	libft/libft.a
HEADER =	./includes/rt_v1.h ./includes/scmk.h
MKINC =		make -C libft/
MLX =		-lmlx -framework OpenGL -framework AppKit
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror
SOURCES1 =	./srcs/rt_v1.c ./srcs/parser.c ./srcs/add_obj.c ./srcs/event.c     \
			./srcs/tools.c
SOURCES2 =	./srcs/scmk.c ./srcs/fill_struct.c ./srcs/obj_types.c              \
			./srcs/tools_scene.c
OBJS1 =		$(SOURCES1:.c=.o)
OBJS2 =		$(SOURCES2:.c=.o)

all :		$(EXE1) $(EXE2)
$(EXE1) :	$(OBJS1) $(HEADER) Makefile
			$(MKINC)
			$(CC) $(CFLAGS) -c $(SOURCES1)
			$(CC) $(CFLAGS) -o $(EXE1) $(OBJS1) -lm $(INCLUDES) $(MLX)
$(EXE2) :	$(OBJS2) $(HEADER) Makefile
			$(MKINC)
			$(CC) $(CFLAGS) -c $(SOURCES2)
			$(CC) $(CFLAGS) -o $(EXE2) $(OBJS2) $(INCLUDES)
norm :
			norminette $(SOURCES1) $(SOURCES2) $(HEADER)
meteo :
			curl http://wttr.in/Paris
clean :
			-rm -f $(OBJS1) $(OBJS2)
fclean :	clean
			$(MKINC) fclean
			-rm -f $(EXE1) $(EXE2)
re :		fclean all
