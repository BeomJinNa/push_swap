CC		= cc
AR		= ar
ARFLAGS	= crs
CFLAGS	= -Wall -Wextra -Werror -g

NAME	= push_swap
LIBS	= libft
ARCH	= ft
INCLUDE	= includes/

SRCS	=	srcs/main.c \
			srcs/get_input_data.c \
			srcs/check_input_data.c \
			srcs/compare_character.c

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
