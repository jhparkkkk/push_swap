NAME 		= 	push_swap

CC			= 	cc

RM 			= 	rm -f

INC			=	-I includes -I libft

CFLAGS		=	-Wall -Wextra -Werror -g

LFLAGS		=	-lft -L ./libft/

LIBFT		=	./libft/libft.a

SRCS		=	push_swap.c \
				parsing.c \
				index.c \
				moves.c \
				utils.c \

OBJS		= 	$(SRCS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< $(OUTPUT_OPTION) $(INC)

$(LIBFT):
			$(MAKE) -C $(@D) $(@F)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(LFLAGS) -g3 -fsanitize=address $(OUTPUT_OPTION)  

clean:
			$(RM) $(NAME) $(OBJS)

fclean:		clean
			$(RM) all

re:			fclean all

.PHONY:		all clean fclean re 