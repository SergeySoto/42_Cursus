NAME = pipex
# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft

# Directories
OBJ_DIR = obj
LIBFT_DIR = ./libft/
INCLUDE = ./libft/libft.h

# Library
LIBFT = $(LIBFT_DIR)libft.a

# Source files
SRC = src/pipex.c src/pipex_utils.c src/arguments.c src/settings.c src/process.c

# Object files (with obj/ prefix)
OBJ = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Default rule
all: $(NAME)

# Build main program
$(NAME): $(OBJ) $(LIBFT)
	@echo "🔧 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME) && \
		echo "✅ Build successful!" || echo "❌ Build failed!"

# Compile .c to .o into obj/
$(OBJ_DIR)/%.o: src/%.c $(INCLUDE)
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
