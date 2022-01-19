#include $(wildcard *.d)

NAME =		so_long

NAME_BONUS = so_long_bonus

SRCS =			src/ft_split.c \
				src/ft_strnchr.c \
				src/ft_strncmp.c \
				src/gnl/get_next_line.c \
				src/gnl/get_next_line_utils.c \
				src_so_long/draw_window.c \
				src_so_long/map_init.c \
				src_so_long/map_validation.c \
				src_so_long/params_validation.c \
				src_so_long/hooks/exit.c \
				src_so_long/hooks/player_control.c \
				src_so_long/hooks/w_control.c \
				src_so_long/hooks/s_control.c \
				src_so_long/hooks/d_control.c \
				src_so_long/hooks/a_control.c \
				src_so_long/hooks/esc_control.c \
				src_so_long/so_long.c \

SRCS_BONUS =	src/ft_split.c \
				src/ft_strnchr.c \
				src/ft_strncmp.c \
				src/ft_itoa.c \
				src/gnl/get_next_line.c \
				src/gnl/get_next_line_utils.c \
				src_so_long_bonus/draw_window_bonus.c \
				src_so_long_bonus/map_init_bonus.c \
				src_so_long_bonus/map_validation_bonus.c \
				src_so_long_bonus/params_validation_bonus.c \
				src_so_long_bonus/hooks/exit_bonus.c \
				src_so_long_bonus/hooks/player_control_bonus.c \
				src_so_long_bonus/hooks/w_control_bonus.c \
				src_so_long_bonus/hooks/s_control_bonus.c \
				src_so_long_bonus/hooks/d_control_bonus.c \
				src_so_long_bonus/hooks/a_control_bonus.c \
				src_so_long_bonus/hooks/esc_control_bonus.c \
				src_so_long_bonus/hooks/trap_control_bonus.c \
				src_so_long_bonus/hooks/draw_counter_bonus.c \
				src_so_long_bonus/hooks/trap_animation_bonus.c \
				src_so_long_bonus/so_long_bonus.c \
		  
OBJ =			$(patsubst %.c,%.o,$(SRCS))

OBJ_BONUS =		$(patsubst %.c,%.o,$(SRCS_BONUS))

CC =			gcc

FLAGS =			-Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -L libs/minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

bonus: $(NAME_BONUS)


$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(FLAGS) $(OBJ_BONUS) -L libs/minilibx_mms_20200219 -lmlx -framework OpenGL -framework AppKit -o $@

re: fclean all

clean:
	rm -f $(OBJ) $(OBJ_BONUS) *.d src_so_long/*.d src/*.d src_so_long/hooks/*.d src_so_long_bonus/hooks/*.d src_so_long_bonus/*.d

fclean: clean
	rm -f  $(NAME) $(NAME_BONUS)

.PHONY: all clean fclean re