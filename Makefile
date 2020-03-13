#	Makefile	#

NAME		= libftprintf.a

SRCS		= 	srcs/add_flag.c
SRCS		+= 	srcs/brain.c
SRCS		+= 	srcs/find.c
SRCS		+= 	srcs/find2.c
SRCS		+= 	srcs/format.c
SRCS		+= 	srcs/format2.c
SRCS		+= 	srcs/functions.c

OBJS	= 	${SRCS:.c=.o}

OBJS_BNS	= 	${SRCS_BNS:.c=.o}

CC		=	gcc  

CFLAGS	= 	-Wall -Werror -Wextra  

MAKE	=	make

INCLUDES_PATH = ./includes/

LIBFT_PATH	= ./srcs/libft/

INCLUDES	= 	$(LIBFT_PATH)libft.h		\
				$(INCLUDES_PATH)functions.h

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

