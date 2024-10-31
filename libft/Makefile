# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 10:39:22 by ade-fran          #+#    #+#              #
#    Updated: 2023/11/13 10:39:25 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libft.a

LIB_PATH		=	lib/

CFLAGS			=	-Wall -Wextra -Werror -I ${INCLD_DIR} -g

CC				=	cc

COLOUR_GREEN	=	\033[0;32m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SOURCES_PATH	=	./

SOURCES_STR		=	ft_str/ft_strlcpy.c \
					ft_str/ft_strrchr.c \
					ft_str/ft_strchr.c \
					ft_str/ft_strlen.c \
					ft_str/ft_strdup.c \
					ft_str/ft_strncmp.c \
					ft_str/ft_strlcat.c \
					ft_str/ft_strnstr.c \
					ft_str/ft_strjoin.c \
					ft_str/ft_strtrim.c \
					ft_str/ft_strmapi.c \
					ft_str/ft_striteri.c \
					ft_str/ft_substr.c \
					ft_str/ft_isalpha.c \
					ft_str/ft_isdigit.c \
					ft_str/ft_isalnum.c \
					ft_str/ft_isprint.c \
					ft_str/ft_isascii.c \
					ft_str/ft_tolower.c \
					ft_str/ft_toupper.c \

SOURCES_MEMORY	=	ft_memory/ft_memchr.c \
					ft_memory/ft_memset.c \
					ft_memory/ft_memcpy.c \
					ft_memory/ft_memmove.c \
					ft_memory/ft_memcmp.c \
					ft_memory/ft_bzero.c \
					ft_memory/ft_calloc.c \

SOURCES_LIST	=	ft_list/ft_lstnew.c \
					ft_list/ft_lstadd_front.c \
					ft_list/ft_lstsize.c \
					ft_list/ft_lstlast.c \
					ft_list/ft_lstadd_back.c \
					ft_list/ft_lstdelone.c \
					ft_list/ft_lstclear.c \
					ft_list/ft_lstiter.c \
					ft_list/ft_lstmap.c \
					ft_list/ft_lstdelfirst.c \
					ft_list/ft_print_list.c \
					ft_list/ft_int_in_lst.c \
					ft_list/ft_lstsort.c \

SOURCES_PRINT	=	ft_print/ft_putchar_fd.c \
					ft_print/ft_putstr_fd.c \
					ft_print/ft_putendl_fd.c \
					ft_print/ft_putnbr_fd.c \
					ft_print/ft_putnbr_base_fd.c \
					ft_print/ft_putptr.c \
					ft_print/ft_printf.c \

SOURCES_SPLIT	=	ft_split/ft_split.c \
					ft_split/ft_count_word.c \
					ft_split/ft_free_strtab.c \

SOURCES_INT		=	ft_int/ft_atoi.c \
					ft_int/ft_itoa.c \
					ft_int/ft_abs.c \

SOURCES_GNL		=	ft_gnl/ft_get_next_line.c \
					ft_gnl/ft_check_new_line.c \

# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJECTS_PATH	=	objs/

OBJECTS			=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_STR:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_MEMORY:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_LIST:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_PRINT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_SPLIT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_INT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_GNL:.c=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./includes/

INCLD			=	${INCLD_DIR}libft.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all: ${NAME}

${NAME} : ${OBJECTS} ${INCLD}
	@mkdir -p lib
	@ar -rcs ${NAME} ${OBJECTS}
	@mv ${NAME} ${LIB_PATH}

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@

clean: 
	rm -rf ${OBJECTS_PATH}

fclean: 
	@rm -rf ${LIB_PATH} ${OBJECTS_PATH}
	@echo "${COLOUR_GREEN}libft cleaned\n${COLOUR_END}"

re: fclean all

.PHONY: fclean clean all re
