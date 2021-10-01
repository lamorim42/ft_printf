SRC = ft_printf.c ft_printf_utils.c ft_put_rt.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

MAIN = testao.c

CC = clang
CCLIB = ar rcs

FLAGS = -Wall -Wextra -Werror
SANITIZE = -g -fsanitize=address
LIBPATH = libft/
LIBFTFLAG = -L $(LIBPATH) -lft
LIB_FLAG = -L. -lftprintf

RM = rm -f

.c.o:
	$(CC) -I $(LIBPATH) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBPATH)
		cp $(LIBPATH)/libft.a $(NAME)
		$(CCLIB) $(NAME) $(OBJ)

libft:
	make -C $(LIBPATH)
	make clean -C $(LIBPATH)

printf: all
	$(CC) $(SANITIZE) $(FLAGS) $(MAIN) -I $(LIBPATH) $(LIB_FLAG) $(LIBFTFLAG)
	./a.out

libft_fclean:
		make fclean -C $(LIBPATH)

clean:
	$(RM) $(OBJ) a.out

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBPATH)

re: fclean all

.PHONY: all libft printf libft_fclean clean fclean re
