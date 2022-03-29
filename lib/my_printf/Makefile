##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile that build the project
##

SRC_DIR = src/
SRC	= 	$(SRC_DIR)my_printf.c \
		$(SRC_DIR)flags.c \
		$(SRC_DIR)utils/intlen.c \
		$(SRC_DIR)utils/my_strlen.c \
		$(SRC_DIR)utils/my_putnbr.c \
		$(SRC_DIR)utils/my_putcharacter.c \
		$(SRC_DIR)utils/my_putstr.c \
		$(SRC_DIR)utils/my_putnbr_base.c \
		$(SRC_DIR)conversions/putcharacter.c \
		$(SRC_DIR)conversions/puthex.c \
		$(SRC_DIR)conversions/putoct.c \
		$(SRC_DIR)conversions/putstr.c \
		$(SRC_DIR)conversions/putnbr.c \
		$(SRC_DIR)conversions/putbin.c \
		$(SRC_DIR)conversions/putptr.c \
		$(SRC_DIR)conversions/putprintable.c \
		$(SRC_DIR)conversions/putmod.c \
		$(SRC_DIR)formatting/alignment.c \
		$(SRC_DIR)formatting/display.c

NAME = libmy_printf.a

IDIR = ./includes

OBJ	= $(SRC:.c=.o)

CFLAGS = -I $(IDIR) -Wall -Wextra

LDFLAGS = -L . -l my

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re: fclean all
