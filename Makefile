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
