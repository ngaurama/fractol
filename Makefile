CC = cc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm -ggdb3
NAME = fractol
SRCS =	fractol.c \
		fractols/julia.c \
		fractols/mandelbrot.c \
		fractols/ship.c \
		helpers/color.c \
		helpers/event_controls.c \
		helpers/ft_atof.c \
		helpers/helpers.c \
		helpers/randomizer.c \
		helpers/zoom.c	

OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
LIBFT = libft/libft.a
MINILIBX = minilibx-linux/libmlx.a

all: $(LIBFT) $(MINILIBX) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	@echo "Compiling fractol..."
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $^ -o $@ $(FLAGS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
#	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C libft --no-print-directory

$(MINILIBX): 
	@echo "Building minilibx..."
	@$(MAKE) -C minilibx-linux --no-print-directory

bonus: all

clean:
	@echo "Cleaning project files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C libft clean --no-print-directory
	@$(MAKE) -C minilibx-linux clean --no-print-directory

fclean: clean
	@echo "Removing $(NAME)..."
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean --no-print-directory
	@$(MAKE) -C minilibx-linux clean --no-print-directory

re: fclean all

.PHONY: all clean fclean re
