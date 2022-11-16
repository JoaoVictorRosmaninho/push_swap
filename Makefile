
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -c
LIB =  -L./lib -lft 
HEADER = libft/libft.h
TARGETS = push_swap.c \
					instructions/sa.c
OBJ_DIR = obj
SRC     = $(addprefix ./src/,$(TARGETS))
OBJ     = $(addprefix ./$(OBJ_DIR)/,$(TARGETS:.c=.o))
LIBFT   = libft.a
VALGRIND_FLAGS = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
NAME = push_swap 

all: re 

re: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) 
	$(CC) $(OBJ) $(LIB) -o $(NAME) 
	$(VALGRIND_FLAGS) ./$(NAME)

$(LIBFT): 
	@echo "compilando libft"
	@make -C ./libft 
	cp libft/$(LIBFT) lib/$(LIBFT)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS)  $< -o $@

$(OBJ_DIR):
	mkdir obj/ 
	mkdir obj/instructions/

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
