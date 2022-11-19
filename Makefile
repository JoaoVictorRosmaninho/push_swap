
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -c
LIB =  -L./lib -lft 
HEADER = libft/libft.h
TARGETS = push_swap.c \
					instructions/sa.c \
					instructions/sb.c \
					instructions/ss.c \
					instructions/pa.c \
					instructions/pb.c \
					instructions/ra.c \
					instructions/rb.c \
					instructions/rra.c

OBJ_DIR = obj
SRC     = $(addprefix ./src/,$(TARGETS))
OBJ     = $(addprefix ./$(OBJ_DIR)/,$(TARGETS:.c=.o))
LIBFT   = libft.a
VALGRIND_FLAGS = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose
NAME = push_swap 

TEST_TARGET = $(TARGETS:push_swap.c=tst/test.c)

NAME_TEST = test 
SRC_TEST  = $(addprefix ./src/,$(TEST_TARGET))
OBJ_TEST  = $(addprefix ./$(OBJ_DIR)/,$(TEST_TARGET:.c=.o))

all: re 

re: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ) 
	$(CC) $(OBJ) $(LIB) -o $(NAME) 
	$(VALGRIND_FLAGS) ./$(NAME)

$(NAME_TEST): $(LIBFT) $(OBJ_DIR) $(OBJ_TEST)
	$(CC) $(OBJ_TEST) $(LIB) -o $(NAME_TEST)
	$(VALGRIND_FLAGS) ./$(NAME_TEST)

$(LIBFT): 
	@echo "compilando libft"
	@make -C ./libft 
	cp libft/$(LIBFT) lib/$(LIBFT)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS)  $< -o $@

$(OBJ_DIR):
	mkdir obj/ 
	mkdir obj/instructions/
	mkdir obj/tst

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)
