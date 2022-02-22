# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: svrielin <svrielin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/17 11:55:20 by svrielin      #+#    #+#                  #
#    Updated: 2022/02/22 09:49:58 by svrielin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:=	get_next_line
CC				:=	gcc
CFLAGS			?=	-Wall -Wextra -Werror

#################################Project_files##################################
SRC_DIR			:=	.
SRC_FILES		:=	get_next-line.c get_next_line_utils.c
OBJ_DIR			:=	./obj
OBJ_FILES		:=	$(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

ifdef DEBUG
CFLAGS	+=	-g
NAME = get_next_line_debug
endif

all: $(NAME)

# $@ filename of the target $^ all prerequisites
# r: uses replacement for the objects files while inserting the files member into archive
# c: create the library if it does not exist
# ar -q: quickly append the .o files of ft_printf to the archive libft.a
# cp: copies libft.a to libftprintf.a
$(NAME): $(OBJ_FILES)
	ar rc $@ $^
	ar -q $(OBJ_FILES)
	cp $(NAME)

# -p: if parent dirs do not exist, generate them to accommodate 
# gcc -c: compile but not link the file, makes the result an object file
# gcc -o: name of the output file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# rm -df instead of rmdir, because this doesn't give an error when dir doesn't exist
# -d: dir, removes empty directories
# -f: force, ignore nonexistant files
clean:
	rm -f $(OBJ_FILES) 
	rm -df $(OBJ_DIR)
	@echo "Object files and directory removed"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean main printf_tester
