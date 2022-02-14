NAME		= philo

CC			=	gcc

C_FLASGS	=	-Wall -Wextra -Werror

OBJS		=	$(SRCS:%.c=%.o)

SRCS		= ./src/error.c \
				./src/init_data.c \
				./src/utils.c \

MAIN 		= 	./src/main.c \

%.o:%.c *.h $(MAIN)
	@$(CC) $(CFLAGS) -pthread  -c $< -o $@
	@printf "\033[0;32m\e[1m%s\033[0m\n" "Compiling..."

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(C_FLASGS) $(OBJS)  $(MAIN) -o $(NAME)


clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME);

re : fclean all




