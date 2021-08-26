CFLAGS = -Wall -Wextra -Werror
CC     = gcc $(CFLAGS)
OBJ    = main.o
INC    = includes
NAME   = ft_display_file

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
