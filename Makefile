CFILES = ft_printf.c ft_printf_utils.c \

OFILES = $(CFILES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME):$(OFILES)
	@ar rc $(NAME) $(OFILES)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean
