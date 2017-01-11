# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 09:55:27 by vroussea          #+#    #+#              #
#    Updated: 2016/12/16 15:45:27 by vroussea         ###   ########.fr        #
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
LIB_A = libft.a

# dir
SRC_DIR =	srcs
OBJ_DIR =	objs
INC_DIR =	includes

# sources
SRC_NAME =	ft_putchar.c ft_putchar_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
			ft_putstr_fd.c ft_putendl.c ft_strlen.c ft_putendl_fd.c ft_strcat.c\
			ft_strcpy.c ft_memalloc.c ft_strnew.c ft_memset.c ft_memcpy.c      \
			ft_toupper.c ft_tolower.c ft_isupper.c ft_islower.c ft_isalpha.c   \
			ft_isdigit.c ft_isalnum.c ft_isascii.c ft_strdup.c ft_strncpy.c    \
			ft_memmove.c ft_itoa.c ft_atoi.c ft_pow.c ft_bzero.c ft_strjoin.c  \
			ft_strdel.c ft_memdel.c ft_strncat.c ft_memccpy.c ft_strchr.c      \
			ft_memchr.c ft_strrchr.c ft_strinv.c ft_strcmp.c ft_isspace.c      \
			ft_strtrim.c ft_memcmp.c ft_strncmp.c ft_strlcat.c ft_isprint.c    \
			ft_strstr.c ft_strnstr.c ft_strsplit.c ft_strclr.c ft_striter.c    \
			ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c    \
			ft_strsub.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c     \
			ft_lstiter.c ft_lstmap.c ft_sqrt.c ft_lstadd_end.c ft_abs.c        \
			get_next_line.c ft_intswap.c ft_tabdel.c ft_matrixid.c             \
			ft_itoa_base.c ft_ltoa_base.c ft_putnbr_base.c ft_putnbr_base_fd.c \
			ft_strrealloc.c ft_swap.c ft_atof.c ft_atod.c

# objects
OBJ_NAME =		$(SRC_NAME:.c=.o)

#paths
SRC =		$(addprefix $(SRC_DIR)/, $(SRC_NAME))
OBJ =		$(addprefix $(OBJ_DIR)/, $(OBJ_NAME))
INC =		$(addprefix -I, $(INC_DIR))

all :		$(LIB_A) $(OBJ)
$(LIB_A) :	$(OBJ)
		@ar rc $@ $(OBJ)
		@ranlib $@
		@echo "$(CLEAR)$(LIG)$(BLUE)  Creating Libft $(CLEAR)$(LIG)"
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR) 2> /dev/null || true
		@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
norme :
		@norminette $(SRC) includes/libft.h
meteo :
		@curl http://wttr.in/Paris
clean :
		@echo "$(CLEAR)$(TRA)$(RED)  Cleaning Object $(CLEAR)$(TRA)"
		@$(RM) $(OBJ)
		@rmdir $(OBJ_DIR) 2> /dev/null || true
fclean :	clean
		@echo "$(CLEAR)$(TRA)$(RED)  Removing Library $(CLEAR)$(TRA)"
			@$(RM) $(LIB_A)
re :		fclean all
.PHONY :	all, clean, fclean, re
.SILENT :
