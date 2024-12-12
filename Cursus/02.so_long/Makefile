NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 #-fsanitize=address

SOURCES = src/main.c src/preliminar_map_check.c src/game/03_game_drawing.c src/game/04_game_movements.c src/auxiliaries.c
OBJECTS = $(SOURCES:.c=.o)

MY_LIB_DIR = ./libft
MINILIBX_DIR = ./minilibx-linux
LIBFT = $(MY_LIB_DIR)/libft.a
MINILIBX_LIB = $(MINILIBX_DIR)/libmlx.a

LIBS = -L$(MY_LIB_DIR) -lft -L$(MINILIBX_DIR) -lmlx -lX11 -lXext

###################################################################################

$(NAME): $(OBJECTS) libft minilibx
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

################################################################################

all: $(NAME)

# Make both libs
libft:
	$(MAKE) -C $(MY_LIB_DIR) bonus
minilibx:
	$(MAKE) -C $(MINILIBX_DIR)

#rule for cleaning objects
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(MINILIBX_DIR) clean
	$(MAKE) -C $(MY_LIB_DIR) clean

#rule for cleaning objects and library
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(MINILIBX_DIR) clean 
	$(MAKE) -C $(MY_LIB_DIR) fclean

#rule for cleaning objects, and library and then rebuild
re: fclean all

################################################################################
.PHONY: all clean fclean re minilibx libft
