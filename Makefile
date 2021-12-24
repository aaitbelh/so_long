NAME = so_long
BONUS_SRCS = so_long_bonus.c ft_check_map_bonus.c move_game_bonus.c update.c animation.c ft_itoa.c needs2.c needs3.c get_next_line.c ft_split.c needs.c 

SRCS = so_long.c ft_check_map.c needs.c needs2.c needs3.c move_game.c get_next_line.c ft_split.c 

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
XFLAGS = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) -o $(NAME)
bonus : $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(XFLAGS)  $(BONUS_OBJS) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $<
clean :
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all