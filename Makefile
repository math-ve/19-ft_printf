NAME =			libftprintf.a
LIBFT_A =		libft.a

COMP =			gcc -Wall -Wextra -Werror $(PRINTF_H) $(LIBFT_H) -c -o

PRINTF_H =		-I includes/
LIBFT_H =		-I srcs/libft/includes

OBJ_DIR = 		obj/
SRC_DIR =		srcs/
LIB_DIR = 		srcs/libft/

CFILE =			ft_printf.c \
				ft_parse_format.c \
				ft_check.c \
				ft_check_all.c \
				ft_dispatch.c \
				ft_utils.c \
				ft_utils2.c \
				ft_c.c \
				ft_d.c \
				ft_s.c \
				ft_u.c \
				ft_x.c \
				ft_xx.c \
				ft_mod.c \
				ft_p.c \
				ft_init.c \
				ft_itoa_base.c \
				ft_itoa_base2.c \
				ft_minus_char.c \
				ft_minus_int.c \
				ft_precision.c \
				ft_precision_s.c \
				ft_width.c \
				ft_write.c \

CFIND =			$(CFILE:%=$(SRC_DIR)%)

OFILE =			$(CFILE:%.c=%.o)

OBJ =			$(addprefix $(OBJ_DIR), $(OFILE))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
		@make -C $(LIB_DIR)
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean flcean re