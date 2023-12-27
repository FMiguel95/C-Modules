NAME = ff7

SRC = AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp
HDR = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp

BIN = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g 
RM = rm -rf

all: $(NAME)

$(NAME): $(BIN)
	$(CXX) $(CXXFLAGS) $(BIN) -o $(NAME)

%.o: %.cpp $(HDR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all
