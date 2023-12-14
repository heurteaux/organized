##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## makefile
##

NAME		=	organized

LIB_NAME	=	./my_printf/libmy.a

LIB			=	my_printf

SRCS	:=	$(shell find $(SRC_DIRS) -name "*.c" \
			-not -name "main.c"	\
			-not -path "./tests/*"	\
			-not -path "./bonus/*")

SRCS_TESTS	:=	$(shell find $(SRC_DIRS) -name "*.c" \
			-not -name "main.c"	\
			-not -path "./lib/*"	\
			-not -path "./tests/*"	\
			-not -path "./bonus/*")

OBJS	=	$(SRCS:.c=.o)

CFLAGS	= -Werror -Wall -Wextra

$(NAME):	$(OBJS)
	make -C lib/my
	gcc -o $(NAME) main.c $(OBJS) ./libshell/libshell.a ./lib/libmy.a

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)
	rm -f ./criterion_tests_bin
	rm -f ./lib/libmy.a
	rm -f ./lib/my/libmy.a

re: fclean all

dev_test: $(OBJS)
	make -C lib/my/
	gcc -o $(NAME) main.c $(OBJS) ./libshell/libshell.a ./lib/libmy.a
	make clean

tests_run:
	echo $(SRCS_TESTS)
	make -C lib/my/
	gcc -o criterion_tests_bin $(SRCS_TESTS) ./tests/*.c -Llib/my \
	make clean
	./criterion_tests_bin
