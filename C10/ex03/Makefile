CFLAGS = -Wall -Wextra -Werror
CC     = gcc $(CFLAGS)
OBJ    = main.o print.o utils.o print2.o
INC    = includes
NAME   = ft_hexdump

.c.o:
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
