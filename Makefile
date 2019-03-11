NAME = printf			#называется libftprintf.a
FLAGS = -Wall -Wextra -Werror		#вставить флагии!!
SRCS = ft_printf.c \
	   processing_functions.c \
	   int_output.c \
	   output_processing_di.c \
	   output_processing_uob.c \
	   output_processing_x.c \
	   char_and_nonstandard_output.c \
	   float_output.c \
	   ft_itoa_base.c \
	   main_xX.c		#убрать итоа бэйз в либу
OBJS = $(SRCS:.c=.o)
INCLUDES = ft_printf.h

all:	$(NAME)

$(NAME):		$(OBJS)
				@echo "\x1b[32;01mCompilation\x1b[32;01m"
				@make --directory ./libft
				@gcc $(OBJS) -o $(NAME) -L ./libft -lft

$(OBJS):		%.o: %.c
				@gcc -c $< -I $(INCLUDES) -o $@
clean:
				@echo "\033[34mDeliting o-files\033[34m"
				@/bin/rm -f $(OBJS)
				@make clean --directory ./libft

fclean: clean
				@echo "\033[34mDeliting binary\033[34m"
				@/bin/rm -f $(NAME)
				@make fclean --directory ./libft

re:		fclean all
