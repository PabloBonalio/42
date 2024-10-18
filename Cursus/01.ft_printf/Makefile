NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_printf.c utils_ft_printf.c
OBJECTS = $(SOURCES:.c=.o)


###################################################################################

# Rule to build libftprintf.a, depending on libft.a
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

################################################################################

# Build the main library
all: $(NAME)

#rule for cleaning objects
clean:
	rm -f $(OBJECTS)

#rule for cleaning objects and library
fclean: clean
	rm -f $(NAME)

#rule for cleaning objects, and library and then rebuild
re: fclean all

################################################################################
.PHONY: all clean fclean re
