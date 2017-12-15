##
## Makefile for minitalk in /home/boitea_r
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Tue Jan 26 22:38:14 2016 Ronan Boiteau
## Last update Sat Feb 20 21:27:23 2016 Ronan Boiteau
##

SERVER	 = server/server
CLIENT	 = client/client

IDIR	 = include/
IDIR_MY	 = lib/my/include/

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my/

CC	 = gcc
CFLAGS	+= -I $(IDIR) -I $(IDIR_MY)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

SRCS_SRV_DIR	= server/src/
SRCS_SRV_FILES	= get_packet.c		\
		  letter.c		\
		  main.c		\
		  my_realloc.c		\
		  signal.c
SRCS_SRV	= $(addprefix $(SRCS_SRV_DIR), $(SRCS_SRV_FILES))

SRCS_CLT_DIR	= client/src/
SRCS_CLT_FILES	= main.c	\
		  send.c
SRCS_CLT	= $(addprefix $(SRCS_CLT_DIR), $(SRCS_CLT_FILES))

OBJS_SRV = $(SRCS_SRV:.c=.o)
OBJS_CLT = $(SRCS_CLT:.c=.o)

RM	 = rm -f


all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	make -C $(LDIR)

$(SERVER): $(OBJS_SRV)
	$(CC) -o $(SERVER) $(OBJS_SRV) -L $(LDIR) -l $(LNAME)

$(CLIENT): $(OBJS_CLT)
	$(CC) -o $(CLIENT) $(OBJS_CLT) -L $(LDIR) -l $(LNAME)

clean:
	$(RM) $(OBJS_SRV) $(OBJS_CLT)
	make -C $(LDIR) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	make -C $(LDIR) fclean

re: fclean all

.PHONY: all clean fclean re
