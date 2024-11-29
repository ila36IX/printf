CC = @cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = $(wildcard libft/*.c) $(wildcard *.c)
OBJ = $(LIBFT:%.c=%.o)
NAME = libftprintf.a
RM = rm -f


all: $(NAME)

$(NAME): $(OBJ)
	ar rsc $@ $?


clean:
	@$(RM) *.o

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
