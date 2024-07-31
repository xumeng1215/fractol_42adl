NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

# MLX_PATH	= minilibx-linux/
MLX_PATH	= minilibx_mac/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

SRCDIR	= src/
SRC = $(SRCDIR)/calc_set.c \
      $(SRCDIR)/color.c \
      $(SRCDIR)/event.c \
      $(SRCDIR)/init.c \
      $(SRCDIR)/main.c \
      $(SRCDIR)/math_utils.c \
      $(SRCDIR)/render.c \
      $(SRCDIR)/str_utils.c

OBJDIR = obj
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDES = -I $(SRCDIR) -I $(MLX_PATH)

all: $(NAME) 

$(NAME): $(OBJ) $(MLX)
	# $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -lXext -lX11 $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) -framework OpenGL -framework AppKit $(INCLUDES)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all re clean fclean
