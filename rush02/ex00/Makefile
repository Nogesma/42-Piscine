CFLAGS = -Wall -Wextra -Werror
CC     = gcc
OBJ    = main.o parsing.o list.o libft.o utils.o numbers.o dict.o
NAME   = rush-02

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean
