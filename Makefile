NAME=libasm.a

SRS=ft_strlen.s \
	ft_strcpy.s

OBJ=$(SRS:.s=.o)

%.o: %.s
	nasm -f elf64 $< -o $@

$(NAME): all

all:
	make $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	make $(NAME)
	gcc -Wall -Wextra -Werror -g3 main.c -L. -lasm -o test
	./test
.PHONY: all clean fclean re
