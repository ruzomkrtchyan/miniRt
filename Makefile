NAME	= miniRt

SRC_DIR 	= src
SUBDIRS 	= utils parsing fill_structs mlx_start math ray_tracing
SRCDIRS 	:= $(addprefix $(SRC_DIR)/, $(SUBDIRS))
SRCS		:= $(notdir $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))) $(notdir $(SRC_DIR)/main.c)

OBJ_DIR	= obj

OBJ 		= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

CC		= cc
HEADER	= $(wildcard ./incs/*.h)
INCLUDE	= -Iincs -Iincludes -I$(LIBFT_DIR)/$(INCLUDES) -Imlx
MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit
LINKERS	= -L$(LIBFT_DIR) -lft $(MLX)
CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=address
MK		= mkdir -p

LIBS		= libft
LIBFT_DIR	= ./libft
INCLUDES	= includes

TEXT		= "\033[6;1m"
GREEN		= "\033[38;2;49;247;196m"
PURPLE		= "\033[38;2;0;138;240m"
RESET		= "\033[0m"

all: mlx $(LIBS) $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) Makefile
	@echo $(GREEN) "$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@" $(RESET)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/*/%.c $(HEADER) Makefile
	@echo $(GREEN) "$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@" $(RESET)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


$(NAME): $(OBJ) $(HEADER)
	@echo $(GREEN) "$(CC) $(CFLAGS) -o $(NAME) $(OBJ)" $(RESET)
	@$(CC) $(CFLAGS) $(LINKERS) -o $(NAME) $(OBJ)

libft :
	@make -C $(LIBFT_DIR)

mlx :
	@cd mlx && make

clean:
	@rm -f $(OBJ)
	@make clean -C mlx
	
fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean $(LIBS) mlx re