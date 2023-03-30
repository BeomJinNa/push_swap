CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -g -Wall -Wextra -Werror

NAME	= push_swap
LIBS	= libft
ARCH	= ft
INCLUDE	= includes/

SRCS	=	srcs/main.c \
			srcs/init_data.c \
			srcs/init_data/check_array_data.c \
			srcs/init_data/check_input_data.c \
			srcs/init_data/compare_character.c \
			srcs/init_data/extract_array_from_input.c \
			srcs/init_data/get_index_table.c \
			srcs/init_data/get_input_data.c \
			srcs/init_data/normalize_the_array.c \
			srcs/init_data/sort_array.c \
			srcs/print_answer.c \
			srcs/solve_push_swap.c \
			srcs/solve_push_swap/do_push.c \
			srcs/solve_push_swap/do_r_rotate.c \
			srcs/solve_push_swap/do_rotate.c \
			srcs/solve_push_swap/do_swap.c \
			srcs/solve_push_swap/get_next_value.c \
			srcs/solve_push_swap/init_stack.c \
			srcs/solve_push_swap/push.c \
			srcs/solve_push_swap/push_less_elems.c \
			srcs/solve_push_swap/put_answer.c \
			srcs/solve_push_swap/recall_one_elem.c \
			srcs/solve_push_swap/rotate.c \
			srcs/solve_push_swap/sort_residual_elems.c \
			srcs/solve_push_swap/swap.c \
			srcs/optimize_the_answer.c

B_SRCS	=

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

ifdef BONUS
	TARGET_OBJS = $(B_OBJS)
else
	TARGET_OBJS = $(OBJS)
endif

.PHONY: all
all :
	$(foreach lib, $(LIBS), make -C $(lib);)
	make $(NAME)

$(NAME) : $(TARGET_OBJS)
	$(CC) -o $(NAME) $(TARGET_OBJS) $(foreach lib, $(LIBS), -L$(lib)) $(foreach arch, $(ARCH), -l$(arch))

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	rm -f $(OBJS) $(B_OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)

.PHONY: re
re :
	make fclean
	make all

.PHONY: bonus
bonus :
	make BONUS=0 all
