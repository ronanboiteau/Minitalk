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

LIB	 = libmy.a
LNAME	 = my
LDIR	 = lib/my

CC	 = gcc
CFLAGS	+= -I $(IDIR)
CFLAGS	+= -Wall -Wextra
CFLAGS	+= -Wpedantic -Wno-long-long
CFLAGS	+= -Werror

SDIR_SRV = server/src/
SRCS_SRV = $(SDIR_SRV)get_packet.c			\
	   $(SDIR_SRV)letter.c				\
	   $(SDIR_SRV)main.c				\
	   $(SDIR_SRV)my_realloc.c			\
	   $(SDIR_SRV)signal.c

SDIR_CLT = client/src/
SRCS_CLT = $(SDIR_CLT)main.c				\
	   $(SDIR_CLT)send.c

OBJS_SRV = $(SRCS_SRV:.c=.o)
OBJS_CLT = $(SRCS_CLT:.c=.o)

RM	 = rm -f


all: $(LIB) $(SERVER) $(CLIENT)

$(LIB):
	cd $(LDIR) && $(MAKE)

$(SERVER): $(OBJS_SRV)
	$(CC) -o $(SERVER) $(OBJS_SRV) -L lib -l $(LNAME)

$(CLIENT): $(OBJS_CLT)
	$(CC) -o $(CLIENT) $(OBJS_CLT) -L lib -l $(LNAME)

clean:
	$(RM) $(OBJS_SRV) $(OBJS_CLT)
	cd $(LDIR) && $(MAKE) clean

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	cd $(LDIR) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
