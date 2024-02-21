NAME=libasm.a

SRS	= ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_write.s

OBJ	= $(SRS:.s=.o)

CC	= nasm -g -f elf64

%.o: %.s
	$(CC) $< -o $@

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all

test:
	make $(NAME)
	gcc -Wall -Wextra -g3 main.c -L. -lasm -o test
	./test
.PHONY: all clean fclean re
