NAME		= libftprintf.a

SRCS		= 	functions.c	\
				main.c

OBJS	= 	${SRCS:.c=.o}

OBJS_BNS	= 	${SRCS_BNS:.c=.o}

CC		=	gcc  

CFLAGS	= 	-Wall -Werror -Wextra

INCLUDES	= 	$(LIBFT_PATH)libft.h	\
				functions.h

MAKE	=	make

LIBFT_PATH	= libft/

$(NAME)	:	$(OBJS) $(INCLUDES)
			$(MAKE) -C $(LIBFT_PATH) bonus
			cp $(LIBFT_PATH)libft.a $(NAME)
			ar rc $(NAME) $(OBJS)

all		:	 $(NAME) $(INCLUDES)

bonus	:	$(OBJS) $(OBJS_BNS) $(INCLUDES)
			ar rc $(NAME) $(OBJS) $(OBJS_BNS)

$(OBJS) : $(INCLUDES)

$(OBJS_BNS) : $(INCLUDES)

clean	:
			$(MAKE) -C $(LIBFT_PATH) clean
			rm -f $(OBJS) $(OBJS_BNS)

fclean	:	clean
			$(MAKE) -C $(LIBFT_PATH) fclean
			rm -f $(NAME)

re 		:	fclean all

comp	:
		clear
		$(CC) $(CFLAGS) main.c libftprintf.a

launch	: all comp
			./a.out

