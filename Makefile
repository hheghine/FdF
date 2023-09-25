NAME			= fdf

SRC_DIR			= src

SRCS			= $(wildcard $(SRC_DIR)/*.c)

HEADER			= $(wildcard includes/*.h)

OBJS			= ${SRCS:.c=.o}

INCS			= -I

CFLAGS			= -Wall -Wextra -Werror #-fsanitize=address -g

MINILIBX		= minilibx_macos

FMS				= -L $(MINILIBX) -framework OpenGL -framework AppKit -lmlx -lm 

ifeq ($(shell uname -s), Linux)
	MINILIBX = minilibx-linux
	FMS = -L $(MINILIBX) -lmlx -lm -lX11 -lXext
endif

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCS)$(MINILIBX) -c $< -o $@

all:	mlx ${NAME}

mlx:
	make -C $(MINILIBX)

${NAME}: ${OBJS}
	$(CC) $(CFLAGS) $(OBJS) $(FMS) -o ${NAME}

clean:
	rm -f $(OBJS)
	make clean -C $(MINILIBX)

fclean: clean
	rm -f ${NAME}

re: 	fclean all

.PHONY: all clean fclean mlx
