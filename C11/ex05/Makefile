CFLAGS = -Wall -Wextra -Werror
CC     = gcc $(CFLAGS)
OBJ    = do-op.o calculator.o utils.o
NAME   = do-op

.c.o:
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) libft.a -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
