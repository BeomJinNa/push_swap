CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror

NAME	= push_swap
B_NAME	= checker
LIBS	= libft
B_LIBS	= libft_bonus
ARCH	= ft
B_ARCH	= ft_bonus
L_NAME	= libft/libft.a
LB_NAME	= libft_bonus/libft_bonus.a
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
			srcs/solve_push_swap/divide_chunk.c \
			srcs/solve_push_swap/do_push.c \
			srcs/solve_push_swap/do_r_rotate.c \
			srcs/solve_push_swap/do_rotate.c \
			srcs/solve_push_swap/do_swap.c \
			srcs/solve_push_swap/init_stack.c \
			srcs/solve_push_swap/push.c \
			srcs/solve_push_swap/push_less_elems.c \
			srcs/solve_push_swap/put_answer.c \
			srcs/solve_push_swap/recall_elems.c \
			srcs/solve_push_swap/recall_one_elem.c \
			srcs/solve_push_swap/rotate.c \
			srcs/solve_push_swap/sort_residual_elems.c \
			srcs/solve_push_swap/swap.c \
			srcs/optimize_the_answer.c

B_SRCS	=	bonus/main_bonus.c \
			bonus/actions/do_push_bonus.c \
			bonus/actions/do_r_rotate_bonus.c \
			bonus/actions/do_rotate_bonus.c \
			bonus/actions/do_swap_bonus.c \
			bonus/actions/init_stack_bonus.c \
			bonus/actions/push_bonus.c \
			bonus/actions/rotate_bonus.c \
			bonus/actions/swap_bonus.c \
			bonus/check_the_result_bonus.c \
			bonus/do_action_bonus.c \
			bonus/get_value_of_action_bonus.c \
			bonus/init_data_bonus.c \
			bonus/init_data/check_array_data_bonus.c \
			bonus/init_data/check_input_data_bonus.c \
			bonus/init_data/compare_character_bonus.c \
			bonus/init_data/extract_array_from_input_bonus.c \
			bonus/init_data/get_index_table_bonus.c \
			bonus/init_data/get_input_data_bonus.c \
			bonus/init_data/normalize_the_array_bonus.c \
			bonus/init_data/sort_array_bonus.c \
			bonus/is_array_sorted_bonus.c

OBJS	= $(SRCS:.c=.o)
B_OBJS	= $(B_SRCS:.c=.o)

.PHONY: all
all :
	make $(NAME)

$(NAME) : $(L_NAME) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(foreach lib, $(LIBS), -L$(lib)) $(foreach arch, $(ARCH), -l$(arch))

$(L_NAME) :
	make -C libft

.PHONY: bonus
bonus :
	make $(B_NAME)


$(B_NAME) : $(LB_NAME) $(B_OBJS)
	$(CC) -o $(B_NAME) $(B_OBJS) $(foreach lib, $(B_LIBS), -L$(lib)) $(foreach arch, $(B_ARCH), -l$(arch))

$(LB_NAME) :
	make -C libft_bonus

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

.PHONY: clean
clean :
	$(foreach lib, $(LIBS), make fclean -C $(lib);)
	$(foreach lib, $(B_LIBS), make fclean -C $(lib);)
	rm -f $(OBJS) $(B_OBJS)

.PHONY: fclean
fclean :
	make clean
	rm -f $(NAME)
	rm -f $(B_NAME)

.PHONY: re
re :
	make fclean
	make all
