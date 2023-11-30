FILES = 1_main.c 2_check_input.c 3_is_sorted.c 4_sort_big.c 5_a_to_b.c 6_sort_three.c 7_b_to_a.c commands.c get_formula.c print_commands.c utils_last.c utils_stack.c utils_size_max_min_map.c
OBJECTS = $(addprefix obj/, $(FILES:.c=.o))
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a
INCLUDES = -I ft_printf/includes -I libft/includes
MAKE = make

all: $(NAME)

$(NAME): $(PRINTF) $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PRINTF) $(LIBFT) $(INCLUDES) -o $(NAME)

$(PRINTF):
	$(MAKE) -C ft_printf

$(LIBFT):
	$(MAKE) -C libft

obj/%.o: %.c
	mkdir -p obj
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(MAKE) -C ft_printf clean
	$(MAKE) -C libft clean
	rm -f $(OBJECTS)

fclean: clean
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean
	$(MAKE) all