NAME = Megaphone
SRC = megaphone.cpp
OBJS = ${SRC:.cpp=.o}
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++98


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS)


%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re