NAME = push_swap

SRC = ft_filter.c \
ft_isint.c \
ft_mind.c \
ft_parser.c \
ft_push_rotate.c \
ft_rotate_2.c \
ft_rotom.c \
ft_show_stacks.c \
ft_sort_utils.c \
ft_sortings.c \
ft_swap.c \
ft_values.c \
ft_sort_utils_2.c \
ft_lis.c \
ft_heapsort.c \
ft_lis_utils.c

MAIN = main.c

TESTs = Test_Env/starting.c

HDR = push_swap.h

UTS = Libft/libft.a

OBJ = $(SRC:.c=.o)

OBJP = $(OBJ) $(MAIN:.c=.o)

OBJT = $(OBJ) $(TESTs:.c=.o)

RM = rm -f

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJP)
	make -C ./Libft/
	gcc $(OBJP) $(UTS) -o $(NAME)

all: $(NAME)

ex: $(NAME)
	make clean
	./push_swap 0 1 4 2112 13 58678 15 2 5 6 8 20 23 12 9 2424 "42 4945 17"

ex2: $(NAME)
	make clean
	time ./push_swap -439 635 966 603 135 -132 -936 411 -411 273 535 938 3 170 -549 -807 726 -92 -418 304 -112 504 132 253 234 661 -9 -667 -42 235 -23 -809 870 559 -147 -93 584 -399 580 -763

test: all
	make clean

test2: $(OBJT)
	make -C ./Libft/
	gcc $(OBJT) $(UTS) -o Test_Env/test

clean:
	${RM} $(OBJP)
	make -C ./Libft/ clean

clear: clean

fclean: clean
	${RM} $(NAME) ${OBJP} $(OBJT)
	make -C ./Libft/ fclean

re: $(NAME)
	make clean

.PHONY: all clean fclean re
