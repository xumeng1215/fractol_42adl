NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Conditional for OS detection
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX_PATH = minilibx-linux/
	MLX_NAME = libmlx.a
	LINK_FLAGS = -lXext -lX11
	INCLUDES = -I $(SRCDIR) -I $(MLX_PATH)
else ifeq ($(UNAME_S),Darwin)
	MLX_PATH = minilibx_mac/
	MLX_NAME = libmlx.a
	LINK_FLAGS = -framework OpenGL -framework AppKit
	INCLUDES = -I $(SRCDIR) -I $(MLX_PATH)
else
$(error Unsupported OS: $(UNAME_S))
endif

MLX = $(MLX_PATH)$(MLX_NAME)

SRCDIR = src/
SRC = $(wildcard $(SRCDIR)/*.c)

OBJDIR = obj
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX) $(LINK_FLAGS) $(INCLUDES)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

norm:
	norminette *.h src/

.PHONY: all re clean fclean
