C = clang
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
LIBFT = libft
DIR_S = sources
DIR_O = temporary
HEADER = include
SOURCES = ft_printf.c \
		  fn_cs.c \
		  fn_di.c \
		  fn_ppercent.c \
		  fn_xxx.c \
		  fn_u.c \
		  fn_padd.c \
		  prepare.c \
		  setter.c \
		  utils.c \


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
