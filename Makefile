NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror

SRC =	ft_printf.c

OBJ = $(patsubst %.c, %.o, $(SRC))
#DEP = $(patsubst %.a, %.h, $(NAME))

LIBFT_PATH = libft/

all: $(NAME) 

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)
	@make -C libft/

$(OBJ): $(SRC) $(DEP)
	$(CC) $(CFLAG) -c $(SRC)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean	
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
	
.PHONY: clean fclean re all

