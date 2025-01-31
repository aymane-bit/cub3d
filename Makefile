# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

NAME = cub3D
BONUS_NAME = cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror 
MLX =  -lmlx -L/usr/lib -lX11 -lXext -lm

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS =  get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		mandatory/gar_co/gar_co.c \
		mandatory/main.c \
		mandatory/error/error.c \
		mandatory/start_game/cub3d.c \
		mandatory/start_game/textures.c \
		mandatory/ray_cast/cast_rays.c \
		mandatory/ray_cast/cast_rays_1.c \
		mandatory/rendering/render_wall.c \
		mandatory/mouvements/mouve.c \
		mandatory/parse/parse_1.c \
		mandatory/parse/parse_2.c \
		mandatory/parse/parse_3.c \
		mandatory/parse/parse_4.c \
		mandatory/parse/parse_5.c \
		mandatory/parse/parse_6.c \
		mandatory/parse/parse_7.c

BONUS_SRCS =  get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		bonus/gar_co/gar_co_bonus.c \
		bonus/main_bonus.c \
		bonus/error/error_bonus.c \
		bonus/start_game/cub3d_bonus.c \
		bonus/start_game/minimap_bonus.c \
		bonus/start_game/textures_bonus.c \
		bonus/ray_cast/cast_rays_bonus.c \
		bonus/ray_cast/cast_rays_1_bonus.c \
		bonus/rendering/render_wall_bonus.c \
		bonus/mouvements/mouve_bonus.c \
		bonus/parse/parse_1_bonus.c \
		bonus/parse/parse_2_bonus.c \
		bonus/parse/parse_3_bonus.c \
		bonus/parse/parse_4_bonus.c \
		bonus/parse/parse_5_bonus.c \
		bonus/parse/parse_6_bonus.c \
		bonus/parse/parse_7_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# **************************************************************************** #
#                                 MAKE RULES                                   #
# **************************************************************************** #

all: display $(LIBFT) $(NAME)

display:
	@echo $(B)
	@echo "\033[1;31m                       _|         _|_|_|     _|_|_|  \033[0m"
	@echo "\033[1;31m   _|_|_|   _|    _|   _|_|_|           _|   _|    _|\033[0m"
	@echo "\033[1;33m _|         _|    _|   _|    _|     _|_|     _|    _|\033[0m"
	@echo "\033[1;33m _|         _|    _|   _|    _|         _|   _|    _|\033[0m"
	@echo "\033[1;34m   _|_|_|     _|_|_|   _|_|_|     _|_|_|     _|_|_|  \033[0m"
	@echo $(X)
	
$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -o $(NAME)

bonus: display $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX) -o $(BONUS_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

# **************************************************************************** #
#                              ADDITIONAL RULES                                #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

.SECONDARY:
