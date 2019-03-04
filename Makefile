NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = 
OBJS = $(SRCS:.c=.o)
INCLUDES = fillit.h

all:    $(NAME)

$(NAME):        $(OBJS)
                @echo "\x1b[32;01mCompilation\x1b[32;01m"
                @make --directory ./libft
                @gcc $(FLAGS) $(OBJS) -o $(NAME) -L ./libft -lft

$(OBJS):        %.o: %.c
                @gcc $(FLAGS) -c $< -I $(INCLUDES) -o $@
clean:
                @echo "\033[34mDeliting o-files\033[34m"
                @/bin/rm -f $(OBJS)
                @make clean --directory ./libft

fclean: clean
                @echo "\033[34mDeliting binary\033[34m"
                @/bin/rm -f $(NAME)
                @make fclean --directory ./libft

re:     fclean all