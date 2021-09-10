NAME = libft.a

SRCS =  ft_memset.c ft_memmove.c ft_bzero.c ft_memcpy.c\
ft_memccpy.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c\
ft_strlcat.c ft_strchr.c ft_isalpha.c ft_isdigit.c ft_atoi.c ft_strrchr.c\
ft_isalnum.c ft_isascii.c ft_isprint.c ft_strnstr.c ft_strncmp.c\
ft_toupper.c ft_tolower.c ft_strdup.c ft_calloc.c ft_substr.c\
ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c ft_strtrim.c\
ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_putendl_fd.c ft_split.c get_next_line.c get_next_line_utils.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstlast.c ft_lstmap.c ft_lstiter.c ft_lstclear.c

OBJC = $(SRCS:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJC)
	ar rcs $(NAME) $?

bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS) $?

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o 
fclean: clean
	rm -rf $(NAME) *.o
re: fclean all