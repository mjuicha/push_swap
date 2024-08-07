CC = cc

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror 

NAME1 = push_swap

NAME2 = checker

SRC = algo.c  class_b.c class_utils2.c ft_atoi.c hypo.c r_rotate.c real.c utils.c algo_utils.c class2.c class_utils1.c class_utils3.c push.c \
		rab.c rotate.c  swap.c main_utils.c linkedlist.c  ft_split.c spec.c \

SRCM = push_swap.c

SRCB = my_checker.c my_algo.c do.c get_next_line.c get_next_line_utils.c 

OBJ = $(SRC:%.c=%.o)

OBJM = $(SRCM:%.c=%.o)

OBJB = $(SRCB:%.c=%.o)

%.o :			%.c    $(HEADER)
	${CC} ${FLAGS} -c $<

all: $(NAME1)

$(NAME1): $(OBJ) $(OBJM)
	$(CC) $(FLAGS) $(OBJ) $(OBJM) -o $@

$(NAME2): $(OBJ) $(OBJB)
	$(CC) $(FLAGS) $(OBJ) $(OBJB) -o $@

bonus: $(NAME2)

clean:
	rm -rf $(OBJ) $(OBJM) $(OBJB)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re bonus