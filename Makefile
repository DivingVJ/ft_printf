NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
  #PATH = libft/

SRC =	ft_printf.c


OBJ = $(patsubst %.c, %.o, $(SRC))
DEP = $(patsubst %.a, %.h, $(NAME))

all: $(NAME) 


$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	@make -C libft/

$(OBJ): $(SRC) $(DEP)
	$(CC) $(CFLAG) -c $(SRC)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@make clean -C libft/

fclean: clean	
	rm -f $(NAME)
	@make fclean -C libft/

re: fclean all
	
.PHONY: clean fclean re all

