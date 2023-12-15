NAME = phonebook

SRC = PhoneBook.cpp Contact.cpp main.cpp

BIN = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
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
