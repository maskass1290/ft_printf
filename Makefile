NAME = libftprintf.a

SRC = ft_printf.c ft_printf_nbrs.c ft_printf_str.c ft_printf_ptr.c

OBJS = $(SRC:%.c=$(OBJ_DIR)/%.o)
OBJ_DIR = OBJ

CFLAGS = -Wall -Werror -Wextra
CC = cc
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re