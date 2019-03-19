NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror		#вставить флагии!!
SRCS = ft_printf.c \
	   processing_functions.c \
	   int_output.c \
	   output_processing_di.c \
	   output_processing_uob.c \
	   output_processing_x.c \
	   char_and_nonstandard_output.c \
	   float_output.c \
	   ft_utoa_base.c \
	   ft_ltoa_base.c \
	   help_functions_for_int.c \
	   get_float_components.c \
	   other_and_bonus.c

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):		text $(OBJS)
				@echo "\x1b[32;01mCompilation Lib\x1b[32;01m"
				@make -C ./libft
				@cp libft/libft.a $(NAME)
				ar rc $(NAME) $(OBJS)

text:
				@echo "Compilation"

$(OBJS):		%.o: %.c
				gcc -c -o $@ $<
clean:
				@echo "\033[34mDeliting o-files\033[0m"
				@/bin/rm -f $(OBJS)
				@make clean --directory ./libft

fclean: clean
				@echo "\033[34mDeliting binary\033[0m"
				@/bin/rm -f $(NAME)
				@make fclean --directory ./libft

re:		fclean all
