NAME = claptrap

SRC = ClapTrap.cpp main.cpp

BIN = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(BIN)
	$(CXX) $(CXXFLAGS) $(BIN) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all
