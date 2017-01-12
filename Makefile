# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2017/01/12 14:50:19 by vroussea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#ansi chars
LOG = 	\033[2K
BLUE = 	\033[1;34m
YELLOW =\033[1;33m
GREEN =	\033[1;32m
RED =	\033[1;31m
CLEAR =	\033[0m
BOLD =	\033[1m
UNDERL =\033[4m
SHI =	\xF0\x9F\x9B\xA1
TRA =	\xF0\x9F\x97\x91
LIG =	\xE2\x9A\xA1
BR_V =	\xe2\x95\x91
BR_H =	\xe2\x95\x90
CR_UR =	\xe2\x95\x97
CR_UL =	\xe2\x95\x94
CR_DR =	\xe2\x95\x9d
CR_DL =	\xe2\x95\x9a

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
LIBMLX =	-L/usr/local/lib -lmlx -lm -framework OpenGL -framework AppKit
LIBFT =		libft/libft.a
LIBOCL =	-framework opencl
MAKELIBFT =	make -C libft/

# sources
SRC_NAME =	rt_v1.c event.c tools.c get_struct.c quad_collide.c raytracer.c    \
			rotations.c
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

all :		$(EXE) $(EXE2)
$(EXE) :	$(SRC) $(OBJ) $(LIBFT)
		@$(CC) $(LIBOCL) $(LIBMLX) $(LIBFT) $(OBJ) -o $@
		@echo "$(CLEAR)$(LIG)$(BLUE)  Compiling "$(EXE)" $(CLEAR)$(LIG)"
$(EXE2) :	$(SRC2) $(OBJ2) $(LIBFT)
		@$(CC) $(LIBMLX) $(LIBFT) $(OBJ2) -o $@
		@echo "$(CLEAR)$(LIG)$(BLUE)  Compiling "$(EXE2)" $(CLEAR)$(LIG)"
$(LIBFT) :
		@$(MAKELIBFT) all
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
norme :
		@$(MAKELIBFT) norme
		@norminette $(SRC) $(SRC2) includes/scmk.h includes/rt_v1.h
meteo :
		@curl http://wttr.in/Paris
cleanlib :
		@$(MAKELIBFT) clean
		@$(RM) $(OBJ) $(OBJ2)
		@rmdir $(OBJ_DIR) 2> /dev/null || true
clean :
		@echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
		@$(RM) $(OBJ) $(OBJ2)
		@rmdir $(OBJ_DIR) 2> /dev/null || true
fclean :	clean
		@echo "$(CLEAR)$(TRA)$(RED)  Removing Binary $(CLEAR)$(TRA)"
		@$(MAKELIBFT) fclean
		@$(RM) $(EXE) $(EXE2)
re :		fclean all
.PHONY :	all, clean, fclean, re
.SILENT :
