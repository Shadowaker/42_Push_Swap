NAME = push_swap
BONNAME = checker

SRC = ft_push_swap.c \
ft_isint.c \
ft_mind.c \
ft_mind_utils.c \
ft_parser.c \
ft_push_rotate.c \
ft_rotate_2.c \
ft_rotom.c \
ft_show_stacks.c \
ft_sort_utils.c \
ft_sortings.c \
ft_swap.c \
ft_values.c \
ft_lis.c \
ft_heapsort.c \
ft_lis_utils.c

BONSRC = Checker_/checker_bonus.c \
Checker_/filter_bonus.c \
Checker_/get_next_line_utils.c \
Checker_/get_next_line.c

MAIN = main.c

HDR = push_swap.h

UTS = Libft/libft.a

OBJ = $(SRC:.c=.o)

OBJP = $(OBJ) $(MAIN:.c=.o)

OBJB = $(OBJ) $(BONSRC:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJP)
	make -C ./Libft/
	gcc $(OBJP) $(UTS) -o $(NAME)

$(BONNAME): $(OBJB)
	make -C ./Libft/
	gcc $(OBJB) $(UTS) -o $(BONNAME)

all: $(NAME)
	make clean

bonus: $(BONNAME)
	make clean

ex: $(NAME)
	make clean
	./push_swap 0 1 4 2112 13 58678 15 2 5 6 8 20 23 12 9 2424 "42 4945 17"

ex2: $(NAME)
	make clean
	time ./push_swap -59 313 505 393 -705 359 704 228 421 -251

test: all
	make clean

clean:
	${RM} $(OBJP) $(OBJB)
	make -C ./Libft/ clean

clear: clean

fclean: clean
	${RM} $(NAME) ${OBJP} $(OBJB)
	make -C ./Libft/ fclean

re:	fclean
	make all
	make clean

.PHONY: all clean fclean re
