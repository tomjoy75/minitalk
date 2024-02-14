SERVER = server

CLIENT = client

SERVER_BONUS = $(SERVER)_bonus

CLIENT_BONUS = $(CLIENT)_bonus

SRC_PATH = srcs

SRC_S = server.c

SRC_C = client.c

SRC_S_BONUS = server_bonus.c

SRC_C_BONUS = client_bonus.c

SRC_S := $(addprefix $(SRC_PATH)/,$(SRC_S))

SRC_C := $(addprefix $(SRC_PATH)/,$(SRC_C))

SRC_S_BONUS := $(addprefix $(SRC_PATH)/,$(SRC_S_BONUS))

SRC_C_BONUS := $(addprefix $(SRC_PATH)/,$(SRC_C_BONUS))

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

OBJ_S_BONUS = $(SRC_S_BONUS:.c=.o)

OBJ_C_BONUS = $(SRC_C_BONUS:.c=.o)

CC = clang

CFLAGS = -Wall -Werror -Wextra -g3 -I. -Ilibft

RM = rm -f

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

all : $(CLIENT) $(SERVER)

$(LIBFT) :
	@make bonus -C $(LIBFT_PATH)

$(CLIENT) : $(LIBFT) ${OBJ_C} Makefile minitalk.h
	$(CC) $(CFLAGS) -o $(CLIENT) -g3 $(OBJ_C) $(LIBFT)

$(SERVER) : $(LIBFT) ${OBJ_S} Makefile minitalk.h
	$(CC) $(CFLAGS) -o $(SERVER) -g3 $(OBJ_S) $(LIBFT)

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : $(LIBFT) ${OBJ_C_BONUS} Makefile minitalk.h
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) -g3 $(OBJ_C_BONUS) $(LIBFT)

$(SERVER_BONUS) : $(LIBFT) ${OBJ_S_BONUS} Makefile minitalk.h
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) -g3 $(OBJ_S_BONUS) $(LIBFT)

clean :
	@make clean -C $(LIBFT_PATH)
	$(RM) $(NAME) $(OBJ_S) $(OBJ_C) $(OBJ_C_BONUS) $(OBJ_S_BONUS)

fclean : clean
	@make fclean -C $(LIBFT_PATH)
	$(RM) $(CLIENT) $(CLIENT_BONUS) $(SERVER) $(SERVER_BONUS)

c :
	make -C $(LIBFT_PATH)
	${CC} -g3 -Ilibft $(SRC) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
