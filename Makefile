SRC_C=src/client.c src/utils.c
SRC_S=src/server.c src/utils.c
OBJ_C=$(SRC_C:src/%.c=obj/%.o)
OBJ_S=$(SRC_S:src/%.c=obj/%.o)
CC=gcc
PRINT=./ft_printf/libftprintf.a
CFLAGS= -Wall -Werror -Wextra
RM=rm -rf

all : creat_dir libcomp server client

creat_dir : 
	mkdir -p obj

libcomp : 
	make -C ./ft_printf

server : $(OBJ_S)
	$(CC) $(CFLAGS) $(PRINT) $(OBJ_S) -o server

client : $(OBJ_C)
	$(CC) $(CFLAGS) $(PRINT) $(OBJ_C) -o client

obj/%.o : src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

fclean : clean
	$(RM) server client
	make -C ./ft_printf fclean

clean :
	$(RM) obj
	make -C ./ft_printf clean

re : fclean all

.PHONY : all, fclean, clean, re