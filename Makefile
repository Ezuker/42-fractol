SRC = \
	main.c \
	mandelbrot.c \
	complex.c \

OBJ = ${SRC:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
NAME = fractol
PRINTF = "./ft_printf"
MLX = "./MLX"
LIBMLX = libmlx42.a
HEADERS	= -I ./include -I ./MLX/include
LIBS	= ./MLX/build/libmlx42.a -ldl -lglfw -pthread -lm

all: ${NAME}

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJ)
	@make -C $(PRINTF)
	@mv $(PRINTF)/libftprintf.a .
	@$(CC) $(OBJ) $(LIBS) $(HEADERS) libftprintf.a -o $(NAME)

clean:
	@make clean -C $(PRINTF)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(PRINTF)
	@$(RM) $(NAME) libftprintf.a

re: fclean all

.PHONY : all clean fclean re
