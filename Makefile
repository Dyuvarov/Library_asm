NAME = libasm.a

SRC = ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s

OBJ = ${SRC:.s=.o}

%.o	: %.s
	nasm -fmacho64 $<

all: ${NAME}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

test: ${NAME}
	gcc main.c -L . -lasm && ./a.out

clean:
	rm -f ${OBJ}

fclean: clean
	rm -f ${NAME}
	rm -f a.out

re: fclean all

.PHONY: all clean fclean re
