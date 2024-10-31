# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 09:53:28 by ade-fran          #+#    #+#              #
#    Updated: 2024/01/31 09:53:30 by ade-fran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

NAME_BONUS		=	pipex_bonus

CFLAGS			=	-Wall -Wextra -Werror -I ${INCLD_DIR} -g

CC				=	cc

COLOUR_GREEN	=	\033[0;32m

COLOUR_END		=	\033[0m

# **************************************************************************** #
#                                                                              #
#                                  LIBFT                                       #
#                                                                              #
# **************************************************************************** #

LIB				=	libft.a

LIBFT_FOLDER 	=	libft/

LIB_DIR			=	${LIBFT_FOLDER}lib/

LIB_SOURCES		=	${LIBFT_FOLDER}*/*.c

LIB_INCLD_DIR	=	${LIBFT_FOLDER}includes/

LIB_INCLD		= 	${LIB_INCLD_DIR}libft.h

LIB_PATH		=	$(addprefix ${LIB_DIR}, ${LIB})

# **************************************************************************** #
#                                                                              #
#                                  SOURCES                                     #
#                                                                              #
# **************************************************************************** #

SOURCES_PATH	=	srcs/

SOURCES_MAIN	= 	main.c \

SOURCES_PARSING	=	parsing/init_data.c \
					parsing/if_heredoc.c \
					parsing/get_heredoc.c \
					parsing/split_env.c \
					parsing/split_cmd.c \
					parsing/search_path.c \
		
SOURCES_EXEC	=	exec/exec.c \
					exec/childs_management/init_child_data.c \
					exec/childs_management/childs_management.c \
					exec/files_management/manage_heredoc.c \
					exec/files_management/manage_infile.c \
					exec/files_management/manage_outfile.c \
					exec/files_management/manage_inter_file.c \

SOURCES_EXIT	=	exit/close_pipe.c \
					exit/exit_child.c \
					exit/get_exit_status.c \
					exit/exit_prog.c \

SOURCES_ERR		=	err_management/err_management.c \

# **************************************************************************** #
#                                                                              #
#                                  OBJECTS                                     #
#                                                                              #
# **************************************************************************** #

OBJECTS_PATH	=	objs/

OBJECTS			=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_MAIN:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_PARSING:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_EXEC:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_EXIT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_ERR:.c=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  SOURCES BONUS                               #
#                                                                              #
# **************************************************************************** #

SOURCES_BONUS	=	main_bonus.c

# **************************************************************************** #
#                                                                              #
#                                  OBJECTS BONUS                               #
#                                                                              #
# **************************************************************************** #

OBJECTS_BONUS	=	$(addprefix ${OBJECTS_PATH}, ${SOURCES_BONUS:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_PARSING:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_EXEC:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_EXIT:.c=.o}) \
					$(addprefix ${OBJECTS_PATH}, ${SOURCES_ERR:.c=.o}) \

# **************************************************************************** #
#                                                                              #
#                                  INCLUDES                                    #
#                                                                              #
# **************************************************************************** #

INCLD_DIR		=	./includes/

INCLD			=	${INCLD_DIR}pipex.h

# **************************************************************************** #
#                                                                              #
#                                  RULES                                       #
#                                                                              #
# **************************************************************************** #

all:  ${NAME}

bonus: ${NAME_BONUS}

${LIB_PATH}: ${LIB_SOURCES} ${LIB_INCLD}
	@echo "Compilation - Libft\n"
	@make -C ${LIBFT_FOLDER} --no-print-directory
	@echo "${COLOUR_GREEN}Libft compiled\n${COLOUR_END}"

${NAME}: ${OBJECTS} ${LIB_PATH} ${INCLD}
	@echo "Compilation - Pipex\n"
	@${CC} ${CFLAGS} ${OBJECTS} ${LIB_PATH} -o ${NAME}
	@echo "${COLOUR_GREEN}Pipex compiled\n${COLOUR_END}"

${NAME_BONUS}: ${OBJECTS_BONUS} ${LIB_PATH} ${INCLD}
	@echo "Compilation - Pipex Bonus\n"
	@${CC} ${CFLAGS} ${OBJECTS_BONUS} ${LIB_PATH} -o ${NAME_BONUS}
	@echo "${COLOUR_GREEN}Pipex Bonus compiled\n${COLOUR_END}"

${OBJECTS_PATH}%.o:	${SOURCES_PATH}%.c
	@mkdir -p ${dir $@}
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@make fclean -C libft/ --no-print-directory
	@rm -rf ${OBJECTS_PATH}

fclean:
	@make fclean -C libft/ --no-print-directory
	@rm -rf ${OBJECTS_PATH}
	@rm -f ${NAME} ${NAME_BONUS}
	@echo "${COLOUR_GREEN}Pipex cleaned\n${COLOUR_END}"

re: fclean all

.PHONY: fclean clean all re bonus
