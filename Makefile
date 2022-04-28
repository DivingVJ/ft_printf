NAME = libftprintf.a
CC = gcc
CFLAG = -Wall -Wextra -Werror
  #PATH = libft/

SRC =	ft_printf.c check_format.c
# INCLUDES = -Ilibft
# LIB	= -Llibft -lft

OBJ = $(patsubst %.c, %.o, $(SRC))
#DEP = $(patsubst %.a, %.h, $(NAME))

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFTOBJ = libft/*.o

all: $(NAME) 


$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)
#	@make -C libft/

$(OBJ): $(SRC) $(DEP)
	$(CC) $(CFLAG) -c $(SRC)

$(LIBFT) :
	make re -C $(LIBFT_PATH)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_PATH)

fclean: clean	
	rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all
	
.PHONY: clean fclean re all

