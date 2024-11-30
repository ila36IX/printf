CC = @cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = $(wildcard libft/*.c) ft_printf.c  helper_functions.c
OBJ = $(LIBFT:%.c=%.o)
NAME = libftprintf.a
RM = rm -f


all: $(NAME)

$(NAME): $(OBJ)
	ar rsc $@ $?

bonus: $(OBJ)
	ar rsc $@ $?

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
