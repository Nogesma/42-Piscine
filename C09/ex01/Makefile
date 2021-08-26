CFLAGS = -Wall -Wextra -Werror
CC     = gcc $(CFLAGS)
OBJ    = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INC    = includes
NAME   = libft.a

.c.o:
	$(CC) -c $< -o $@ -I$(INC)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
