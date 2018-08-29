NAME = fdf

SRCS =  ./srcs/main.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SRCS:.c=.o)

LIB			= libft/libft.a

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[01;38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m
RES			= \033[m

all: $(NAME)
	@echo  "$(YELLOW) : OK$(RES)"

$(NAME): $(LIB) $(OBJECTS)
	@ gcc $(CFLAGS) -I. $(SRCS) -L ./libft -lft -o $(NAME)

$(LIB):
	@echo  "$(GREEN)Compiling: $(WHITE)libft$(RES)$(YELLOW) : $(RES)\c)"
	@make -C libft
	@echo  "$(GREEN)Compiling: $(WHITE)fdf  $(RES)$(YELLOW) : $(RES)\c)"

$(OBJECTS): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo  "$(YELLOW)█$(RES)\c)"

clean:
	@ make -C libft clean
	@ rm -f $(OBJECTS)

fclean: clean
	@ rm -f $(NAME) $(LIB)
	@ make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
