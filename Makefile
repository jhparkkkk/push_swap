NAME 		= 	push_swap
CHECKER		=	checker

CC			= 	cc

RM 			= 	rm -f

INC			=	-I includes -I libft

CFLAGS		=	-Wall -Wextra -Werror

LFLAGS		=	-I./libft -lft -L./libft

LIBFT		=	./libft/libft.a

SRCS		=	push_swap.c \
				check_error.c \
				init.c \
				little_sort.c \
				swap.c \
				push.c \
				rotate.c \
				reverse_rotate.c \
				longest_list_1.c \
				longest_list_2.c \
				departure.c \
				departure_utils.c \
				target.c \
				simulation.c \
				moves.c \
				sync.c \
				arrival.c \
				utils.c \

SRCS_C		=	checker.c \
				check_error.c \
				init.c \
				longest_list_1.c \
				longest_list_2.c \
				push.c \
				swap.c \
				rotate.c \
				reverse_rotate.c \
				utils.c \

OBJS		= 	$(SRCS:.c=.o)
OBJS_C		= 	$(SRCS_C:.c=.o)

all:		$(NAME) 
bonus:		$(CHECKER)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION) $(INC)

$(LIBFT):
			$(MAKE) -C $(@D) $(@F)

$(NAME):	$(LIBFT) $(OBJS) 
			$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION)  

$(CHECKER):	$(LIBFT) $(OBJS_C)
			$(CC) $(OBJS_C) $(LFLAGS) $(OUTPUT_OPTION)
clean:
			$(RM) $(NAME) $(OBJS) $(OBJS_C) $(LIBFT)
			$(RM) ./libft/*.o

fclean:		clean
			$(RM) $(NAME) $(CHECKER)

re:			fclean all bonus

.PHONY:		all checker bonus clean fclean re
