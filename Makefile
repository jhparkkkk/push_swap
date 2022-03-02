NAME 		= 	push_swap

CC			= 	cc

RM 			= 	rm -f

INC			=	-I includes -I libft

CFLAGS		=	-Wall -Wextra -Werror -g

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
				longest_list.c \
				departure.c \
				target.c \
				simulation.c \
				moves.c \
				sync.c \
				arrival.c \
				utils.c \

OBJS		= 	$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION) $(INC)

$(LIBFT):
			$(MAKE) -C $(@D) $(@F)

$(NAME):	$(LIBFT) $(OBJS) 
			$(CC) $(OBJS) $(LFLAGS) $(OUTPUT_OPTION)  

clean:
			$(RM) $(NAME) $(OBJS) $(LIBFT)

fclean:		clean
			$(RM) all

re:			fclean all

.PHONY:		all clean fclean re 