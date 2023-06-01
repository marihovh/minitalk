CC = cc
NAME = libftprintf.a
HEADER  = ft_printf.h
SRC = ft_printf_utils.c ft_printf.c ft_printf_utils2.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
AR = @ar rcs
RM = @rm -f

all	: $(NAME)

%.o : %.c $(HEADER)
	@($(CC) $(CFLAGS) -c $< -o $@)

$(NAME)	: $(OBJ)
	$(AR) $(NAME) $(OBJ)

fclean		: clean 
	$(RM) $(NAME)
	
clean : 
	$(RM) $(OBJ)

re: fclean all
	
.PHONY : all, clean, fclean, re,
