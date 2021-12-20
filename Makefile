Name = so_long
SRCS = so_long.c ft_check_map.c needs.c \
		needs2.c get_next_line.c move_game.c \
		ft_split.c needs3.c


OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra

all : $(Name)
$(Name) : $(OBJS)
	 $(CC) $(FLAGS) -framework OpenGL -framework AppKit -lmlx $(OBJS)  -o $(Name)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(Name)
re : fclean all