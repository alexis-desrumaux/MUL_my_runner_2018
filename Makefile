##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makefile
##

Filename	=	$(shell echo ./*.c | cut -f2 -d '.' | cut -f2 -d '/')

File	=	$(shell echo ./*.c)

SRC	=	lib/my/libmy.a	\

NAME	=	my_runner

all:	$(NAME)

$(NAME):
	cd ./lib/my/ && gcc -c *.c && ar rc libmy.a *.o && rm *.o && cd ../../ && gcc my_runner.c my_runner_part2.c my_runner_part3.c my_runner_part4.c my_runner_part5.c my_runner_part6.c my_runner_part7.c my_runner_part8.c my_runner_part9.c my_runner_part10.c struct_def.c struct_def_part2.c -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio $(SRC) -o my_runner

clean:
	rm -f $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
