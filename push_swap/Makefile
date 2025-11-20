NAME = push_swap
BONUS_NAME = checker
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

# Directories
BONUS_SRC = src_bonus/push_swap.c src_bonus/parsing.c src_bonus/push_utils.c src_bonus/func_error.c src_bonus/nodes.c\
src_bonus/get_input.c src_bonus/actions.c src_bonus/moves_A.c src_bonus/moves_B.c src_bonus/move_both.c\
src_bonus/parse_input.c src_bonus/prints.c
SRC_DIR = .
OBJ_DIR = obj
LIBFT_DIR = ./libft/
INCLUDE = ./libft/libft.h

# Library
LIBFT = $(LIBFT_DIR)libft.a

# Source files
SRC = src/push_swap.c src/parsing.c src/push_utils.c src/func_error.c src/nodes.c\
src/get_input.c src/actions.c src/moves_A.c src/moves_B.c src/move_both.c\
src/node_utils.c src/sorting_p1.c src/sorting_p2.c src/parse_input.c src/prints.c \
src/cost.c src/target.c src/path.c src/path_move.c src/algorithm_utils.c\

# Object files (with obj/ prefix)
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))
OBJ_BONUS = $(patsubst src_bonus/%.c, $(OBJ_DIR_BONUS)/%.o, $(BONUS_SRC))
OBJ_DIR_BONUS = bonus_obj


# Default rule
all: $(NAME)

# Build main program
$(NAME): $(OBJ) $(LIBFT)
	@echo "🔧 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) && \
		echo "✅ Build successful!" || echo "❌ Build failed!"

bonus: $(OBJ_BONUS) $(LIBFT)
	@echo "🔧 Linking $(BONUS_NAME)..."
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME) && \
		echo "✅ Build successful!" || echo "❌ Build failed!"

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: src/%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "🟢 Compiled $<" || echo "🔴 Failed to compile $<"

$(OBJ_DIR_BONUS)/%.o: src_bonus/%.c $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ && \
		echo "🟢 Compiled $<" || echo "🔴 Failed to compile $<"

# Compile libft with messages
$(LIBFT):
	@echo "📦 Compiling libft..."
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@if [ $$? -eq 0 ]; then \
		echo "✅ libft compiled successfully!"; \
	else \
		echo "❌ Failed to compile libft!"; \
		exit 1; \
	fi

# Rule to run a test build
ejecutarall: $(SRC) $(LIBFT)
	@echo "🚀 Compiling test version..."
	@$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -lft -o push_swap_test && \
		./push_swap_test

# Clean object files
clean:
	@echo "🧹 Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

# Clean everything
fclean: clean
	@echo "🧹 Removing binaries..."
	@rm -f $(NAME) push_swap_test
	@rm -f $(BONUS_NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

# Rebuild all
re: fclean all

.PHONY: all clean fclean re ejecutarall
