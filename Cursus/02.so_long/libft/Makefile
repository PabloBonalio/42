CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_split.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf.c utils_ft_printf.c \
get_next_line.c get_next_line_utils.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstadd_back_bonus.c \
ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_lstlast_bonus.c 

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(BONUS:.c=.o)

################################################################################

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

################################################################################

#rule for building the library w/o bonus
all: $(NAME)

#rule for cleaning objects including bonus
clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

#rule for cleaning objects and library
fclean: clean
	rm -f $(NAME)

#rule for cleaning objects, and library and then rebuild
re: fclean all

#rule for building library including bonus
bonus: $(OBJECTS) $(BONUS_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

################################################################################
.PHONY: all clean fclean re bonus
