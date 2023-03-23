CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror -g

NAME	= push_swap
LIBS	= libft
ARCH	= ft
INCLUDE	= includes/

SRCS	=	srcs/main.c \
			srcs/init_data.c \
			srcs/init_data/get_input_data.c \
			srcs/init_data/check_input_data.c \
			srcs/init_data/check_array_data.c \
			srcs/init_data/compare_character.c \
			srcs/init_data/extract_array_from_input.c \
			srcs/init_data/get_index_table.c \
			srcs/init_data/sort_array.c \
			srcs/init_data/normalize_the_array.c \
			srcs/solve_push_swap.c

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
