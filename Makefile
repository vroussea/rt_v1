# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/11/19 18:27:16 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ansi chars
LOG = \033[2K
YELLOW = \033[1;33m
GREEN = \033[1;32m
RED = \033[1;31m
CLEAR = \033[0m
BOLD = \033[1m
UNDERL = \033[4m
BORD_V = \xe2\x95\x91
BORD_H = \xe2\x95\x90
BLUE = \033[34m
BLUE1 = \033[34m

# comp
CC =		clang
CFLAGS =	-Wall -Wextra -Werror

# binaries
EXE =		rtv1
EXE2 =		scmk

# dir
SRC_DIR =	srcs
OBJ_DIR =	objs
INC_DIR =	includes

# libs
LIB =		-L/usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit     \
			-Llibft -lft
MAKELIBFT =	make -C libft/

# sources
SRC_NAME =	rt_v1.c event.c tools.c get_struct.c
SRC2_NAME =	scmk.c fill_struct.c obj_types.c tools_scene.c

# objects
OBJ_NAME =		$(SRC_NAME:.c=.o)
OBJ2_NAME =		$(SRC2_NAME:.c=.o)

#paths
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_NAME))
SRC2 =		$(addprefix $(SRC_DIR)/, $(SRC2_NAME))
OBJ =		$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
OBJ2 =		$(addprefix $(OBJ_DIR)/, $(OBJ2_NAME))
INC =		$(addprefix -I, $(INC_DIR))

all :		libftcomp $(EXE) $(EXE2)
libftcomp :
		@$(MAKELIBFT) all
$(EXE) :	$(OBJ) $(OBJ2) libftcomp
		@echo "a$(BLUE)$(BORD_H)$(CLEAR)"
		@echo "a$(BLUE1)$(BORD_H)$(CLEAR)"
		@$(CC) $(LIB) $(OBJ) -o $@
		@$(CC) $(LIB) $(OBJ2) -o $(EXE2)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
norme :
		@$(MAKELIBFT) norme
		@norminette $(SRC) $(SRC2) $(INC)
meteo :
		@curl http://wttr.in/Paris
cleanlib :
		@$(MAKELIBFT) clean
		@$(RM) $(OBJ) $(OBJ2)
		@rmdir $(OBJ_DIR) 2> /dev/null || true
clean :
		@$(RM) $(OBJ) $(OBJ2)
		@rmdir $(OBJ_DIR) 2> /dev/null || true
fclean :	clean
		@$(MAKELIBFT) fclean
		@$(RM) $(EXE) $(EXE2)
re :		fclean all
.PHONY:	all, clean, fclean, re
