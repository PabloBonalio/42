NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = src/main.c src/map/map_compose.c src/map/preliminar_map_check.c \
	src/game/game_cicle.c src/game/game_movements.c src/auxiliaries.c\
	 src/graphic_preps/draw_map.c src/graphic_preps/choose_player.c \
	src/graphic_preps/graphic_preps.c #src/graphic_preps/prep_animations.c
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
