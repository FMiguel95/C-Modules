NAME = logger

SRC = Account.cpp tests.cpp

BIN = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -g -Wall -Werror -Wextra -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(BIN)
	$(CC) $(CFLAGS) $(BIN) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all
