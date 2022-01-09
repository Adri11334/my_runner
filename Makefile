##
## EPITECH PROJECT, 2021
## Project Generator
## File description:
## Autocreated Makefile
##

SRC	=	src/error_manager.c	\
		src/animator/animator.c	\
		src/animator/jumping.c	\
		src/animator/menu.c	\
		src/animator/running.c	\
		src/display/background.c	\
		src/display/enemys.c	\
		src/display/menu.c	\
		src/display/object.c	\
		src/display/parallax.c	\
		src/display/score.c	\
		src/events/analyse.c	\
		src/events/end.c	\
		src/events/fullscreen.c	\
		src/events/jumping.c	\
		src/events/leave_game.c	\
		src/events/start_game.c	\
		src/load/characters.c	\
		src/load/create_elements.c	\
		src/load/gameobject.c	\
		src/load/infin_mode.c	\
		src/load/load_up.c	\
		src/load/map.c	\
		src/load/user.c	\
		src/manager/game.c	\
		src/manager/menu.c	\
		src/manager/victory.c	\
		src/game.c	\
		src/help.c	\
		src/pre_loading.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

CFLAGS	+=	-w -Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

LDFLAGS	=	-lcsfml-graphics -lcsfml-system  -lcsfml-audio

CPPFLAGS	+=	-L./lib -lmy
CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-g

all:	$(NAME)

lib:
	make -C ./lib/my

$(NAME):	lib	$(OBJ)
		gcc main.c $(OBJ) -o $(NAME) -ggdb3 $(LDFLAGS) $(CPPFLAGS)
		@rm -f $(OBJ)

debug:	CPPFLAGS += -ggdb3
debug:	CPPFLAGS += -g
debug:	NAME = dbg
debug:	lib	$(OBJ)
		gcc main.c $(OBJ) -o $(NAME) $(LDFLAGS) $(CPPFLAGS)
		valgrind ./$(NAME) map/map1

tests_run:	NAME = unit_tests
tests_run:	CPPFLAGS += --coverage
tests_run:	CPPFLAGS += -lcriterion
tests_run:	$(OBJ)
tests_run:	lib
	gcc -o $(NAME) $(OBJ) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
	@-./$(NAME)
	@rm $(NAME)

cover:
	@mkdir -p criterions_r
	@gcovr --exclude tests/ --html --html-details -o criterions_r/cover.html
	@gcovr --branches --exclude tests/
	@make -C ./ clean

clean:
	make -s -C ./lib/my clean
	@find . -type f | xargs touch
	@rm -f $(OBJ)
	@rm -f *.o
	@rm -f *~
	@rm -f vgcore*
	@rm -f #*
	@rm -f *.gcda
	@rm -f *.identifier
	@rm -f *.gcno

fclean:	clean
	make -s -C ./lib/my fclean
	rm -f $(NAME)
	@rm -f criterions_r/*.html
	@rm -f criterions_r/*.css
	@rm -rf criterions_r/
	@rm -f *Zone.Identifier
	@rm -f projet
	@rm -f *.gcno

my_tests: tests_run cover

valgrind:	debug
	valgrind --leak-check=full --track-origins=yes -s ./dbg > valgrind.txt 2>&1
	make -C ./ clean

re:	fclean all

run:	re
	-./$(NAME)

.PHONY: all clean fclean re tests_run cover lib run valgrind
