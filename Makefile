NAME			= fdf
SRC_DIR 		= src
SRCS			= $(wildcard $(SRC_DIR)/*.c)
HEADERS			= $(wildcard includes/*.h)
OBJ_DIR			= obj
OBJS			= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
INCS			= -Iincludes
CC				= cc 
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@ #-fsanitize=address -g
MK				= mkdir -p

all:			$(OBJ_DIR) $(NAME)

$(OBJ_DIR): $(SRC_DIR)
	$(MK) $(OBJ_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(INCS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) $(OBJS)

clean:			
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)
				
re:				fclean all

.PHONY:			all clean fclean re bonus
