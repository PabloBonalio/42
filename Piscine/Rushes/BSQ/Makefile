MAIN = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_find_solution.c

OBJS = $(SRCS: .c=.o)

all: $(MAIN)

$(MAIN):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(MAIN)

re: fclean all

.PHONY: clean fclean re all bonus