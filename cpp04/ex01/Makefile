NAME=settheworldonfire
FILES= Brain Dog Cat Animal main
FLAGS= -Wall -Wextra -Werror -std=c++98 -g
SRC_FILES = $(addsuffix .cpp, $(FILES))
OBJ_FILES = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJ_FILES)
	c++ $(FLAGS) -I./ $(OBJ_FILES) -o $(NAME)

%.o: %.cpp
	c++ $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
