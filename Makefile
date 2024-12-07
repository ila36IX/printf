CC = @cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_nbrbase.c  ft_nbrbase_utils.c  ft_parsers.c  ft_printf.c  ft_ptr_helpers.c  ft_str_helpers.c
PRINTF_OBJ = $(PRINTF:%.c=%.o)
NAME = libftprintf.a
RM = rm -f


all: $(NAME)

$(NAME): $(PRINTF_OBJ)
	ar rsc $@ $?

bonus: $(NAME)

clean:
	@$(RM) $(PRINTF_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)
